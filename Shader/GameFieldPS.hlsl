#include "Common.hlsl"
#include "Noise.hlsl"

PS_OUTPUT_GEOMETRY main(PS_INPUT input)
{
    PS_OUTPUT_GEOMETRY output;
       
    float4 baseColor;
	//baseColor = TextureBaseColor.Sample(Sampler, input.TexCoord);
	
    float2 texCoord = input.TexCoord;
    texCoord.x *= 1.5;
    texCoord.y *= 1.5;
    float noise = fbm2(texCoord, 9);
    float wood = sin(noise * 5.0);
    //baseColor.rgb = lerp(float3(0.6, 0.5, 0.8),
				//		 float3(0.2, 0.2, 0.1),
				//		 wood);
    
    float h = (input.WorldPosition.y + 100) / -150;
   baseColor.rgb = lerp(float3(0.0, 1.0, 0.0),
							float3(0.0, 1.0, 0.5),
							h);
    baseColor.a =0.1;
	
    output.Color = input.Color * Material.BaseColor * baseColor;
    
	//ñ@ê¸éZèo
    float dx = GetFieldHeight(input.WorldPosition.xz + float2(0.1f, 0.0f), Field.x, Field.y, Field.z)
	         - GetFieldHeight(input.WorldPosition.xz - float2(0.1f, 0.1f), Field.x, Field.y, Field.z);
	
    float dz = GetFieldHeight(input.WorldPosition.xz + float2(0.0f, 0.1f), Field.x, Field.y, Field.z)
			 - GetFieldHeight(input.WorldPosition.xz - float2(0.0f, 0.1f), Field.x, Field.y, Field.z);
	
    float3 normal = float3(-dx, 0.1f, -dz);
	
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
	
    output.Emission = Material.EmissionColor;


    return output;
}
