#include "Common.hlsl"
#include "Noise.hlsl"


PS_OUTPUT_GEOMETRY main(PS_INPUT input)
{
    PS_OUTPUT_GEOMETRY output;
              
	//float4 baseColor;
	//baseColor = TextureBaseColor.Sample(Sampler, input.TexCoord);
	//output.Color = input.Color * Material.BaseColor * baseColor;
    
    output.Color = float4(0.0f, 0.0f, 0.0f, 1.0f);
	
    float3 normal = input.Normal;
    normal = normalize(normal);
    output.Normal.rgb = normal;
    output.Normal.a = 1.0f;
	
    float3 position = input.WorldPosition.xyz;
    output.Position.rgb = position;
    output.Position.a = 1.0f;
	
    output.Material.r = Material.Metallic;
    output.Material.g = Material.Specular;
    output.Material.b = Material.Roughness;
    output.Material.a = 1.0;
	
	//output.Emission = Material.EmissionColor;
		
    float3 eyeVec = position.xyz - CameraPosition.xyz;
    eyeVec = normalize(eyeVec);
    float2 cloudPosition = eyeVec.xz * 1000 / eyeVec.y;
	
    
	//ドメインワーピング
    float2 warp;
    warp.x = fbm2(cloudPosition * 0.05, 3, Time * 0.2);
    warp.y = fbm2(cloudPosition * 0.05 + 1.0, 3, Time);

    float2 noise = fbm2(cloudPosition * 0.001 + Time, 6, Time * 0.2, 3.0);
	
    //float2 noise = fbm2(cloudPosition * 0.01 + warp, 6, Time * 0.1);
	
    float cloud = saturate(noise + 0.001);
	
    float3 skyColor = output.Emission.rgb = lerp(float3(0.1, 0.1, 0.9),
												 float3(1.0, 1.0, 1.0),
												 cloud);
	
    output.Emission.rgb = lerp(float3(1.0, 1.0, 1.0),
							   skyColor,
							   saturate(eyeVec.y * 10.0));
	
    output.Emission.a = 1.0;

    return output;
}
