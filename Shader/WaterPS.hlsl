#include "Common.hlsl"
#include "Noise.hlsl"


PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output;


	//法線算出
    float dx = GetWaterHeight(input.WorldPosition.xz + float2(0.1f, 0.0f), Water.y, Time, Water.x)
	         - GetWaterHeight(input.WorldPosition.xz - float2(0.1f, 0.01), Water.y, Time, Water.x);
	
    float dz = GetWaterHeight(input.WorldPosition.xz + float2(0.0f, 0.1f), Water.y, Time, Water.x)
			 - GetWaterHeight(input.WorldPosition.xz - float2(0.0f, 0.1f), Water.y, Time, Water.x);
	
    float3 normal = float3(-dx, 1.0f, -dz);
    
    normal = normalize(normal);
    
    //ハーフランバート
    //float3 normal = normalize(input.Normal.rgb);
    //output.Color.rgb = saturate(dot(LightDirection.xyz, normal.xyz) * 0.5 + 0.5);
    //output.Color.rgb *= fbm2(input.WorldPosition.xz * 0.1, 8, Time);
    
    //視線ベクトル生成
    float3 eyeVec = input.WorldPosition.xyz - CameraPosition.xyz;
    eyeVec = normalize(eyeVec);
    
    //反射ベクトル
    float3 refVec = reflect(eyeVec, normal);
    
    //フレネル反射率(Schlick近似式)
    float f0 = 0.02;
    float d = saturate(dot(-eyeVec, normal));
    float fresnel = f0 + (1.0 - f0) * pow((1.0 - d), 5.0);
    
    float3 atomColor = GetAtomColorWater(refVec);
    
    output.Color.rgb = atomColor; //空の反射色(空の色に合わせる)
    output.Color.a = fresnel;

    return output;
}
