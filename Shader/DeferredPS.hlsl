#include "Common.hlsl"

float D_GGX(float m2, float NH)
{
    float f = (NH * m2 - NH) * NH + 1;
    return m2 / (PI * f * f);
}

float G2_Smith(float NL, float NV, float m2)
{
    float NL2 = NL * NL;
    float NV2 = NV * NV;
    
    float Lambda_V = (-1.0f + sqrt(m2 * (1.0f - NL2) / NL2 + 1.0f)) * 0.5f;
    float Lambda_L = (-1.0f + sqrt(m2 * (1.0f - NV2) / NV2 + 1.0f)) * 0.5f;
    
    return 1.0f / (1.0f + Lambda_L + Lambda_V);

}

float3 SchlickFresnel(float3 specular, float VH)
{
    return specular + (1.0f - specular) * pow((1.0f - VH), 5.0f);
}

PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output;
    
    float2 texCoord = input.TexCoord;
    
    float4 baseColor = TextureBaseColor.Sample(Sampler, texCoord).rgba;
    float3 normal = TextureNormal.Sample(Sampler, texCoord).rgb;
    float3 position = TexturePosition.Sample(Sampler, texCoord).rgb;
    float3 lightDirection = float3(0.0f, Material.Specular, 0.0f);
    
    float metallic = Material.Metallic;  //金属
    float roughness = Material.Roughness; //粗さ
    
    //ライティング処理
    float light = dot(lightDirection, normal);
    light = saturate(light);
    
    //視線ベクトル
    float3 eyev = CameraPosition.xyz - position.xyz;
    eyev = normalize(eyev);
    
    //反射ベクトル
    float3 refv = reflect(eyev, normal.xyz);
    refv = normalize(refv);
    
    //拡散反射
    float3 diffuse;
    float3 specular;
    {
        //ハーフランバート
        diffuse = saturate(dot(lightDirection.xyz, normal.xyz) * 5.0 + 5.0);
        diffuse *= baseColor.rgb;
        diffuse *= LightColor.rgb;
        diffuse *= (1.0f - metallic);
        
        diffuse /= PI;
    }
    
    //ハーフベクトル
    float3 halfv = eyev + lightDirection;
    halfv = normalize(halfv);

    //鏡面反射
    //GGX
    {
        float3 N = normal;
        float3 L = lightDirection.xyz;
        float3 V = eyev;
        float3 H = normalize(V + L);
    
        float NV = saturate(dot(N, V));
        float NH = saturate(dot(N, H));
        float NL = saturate(dot(N, L));
        float VH = saturate(dot(V, H));
    
        float4 color = baseColor;
        float3 Kd = baseColor * (1.0f - metallic);
    
        float3 Ks = baseColor * metallic + 0.04f;   //Metallic
        float a = roughness * roughness;    //Roughness
        float m2 = a * a;
        float D = D_GGX(m2, NH);
        float G2 = G2_Smith(NL, NV, m2);
        float3 Fr = SchlickFresnel(Ks, VH);
        
        specular = (D * G2 * Fr) / (4.0f * NV * NL + 0.0001);
        specular *= LightColor.rgb;
    }
        
    output.Color.rgb = diffuse.rgb + specular.rgb;
    output.Color.a = 1.0f;

    return output;
}

