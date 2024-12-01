#include "Common.hlsl"

PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output;
    
 	//法線を正規化して格納する
    float4 normal = normalize(input.Normal);
    float3 light_direction = (0.0f, 1.0f, 1.0f);
  
    
	//ランバート拡散照明
    float light = -dot(light_direction, normal.xyz);
    light = saturate(light);

	//テクスチャから色をサンプリングする
    output.Color = TextureBaseColor.Sample(Sampler, input.TexCoord);
    output.Color.rgb *= light;
    output.Color.a *= input.Color.a;
    
    //鏡面反射
    float3 eyev = input.WorldPosition.xyz - CameraPosition.xyz;
    eyev = normalize(eyev);
    
    float3 halfv = eyev + light_direction;
    halfv = normalize(halfv);
    
    float specular = -dot(halfv, normal.xyz);
    saturate(specular);
    specular = pow(specular, 30);
    output.Color.rgb = saturate(output.Color.rgb + specular);
    
    return output;
}