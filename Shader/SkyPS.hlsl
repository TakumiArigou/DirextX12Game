#include "Common.hlsl"
#include "Noise.hlsl"


PS_OUTPUT_GEOMETRY main(PS_INPUT input)
{
    PS_OUTPUT_GEOMETRY output;
    
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
		
    float3 eyeVec = position.xyz - CameraPosition.xyz;
    eyeVec = normalize(eyeVec);
    float2 cloudPosition = float2(eyeVec.xz * 1000 / eyeVec.y);
	
    cloudPosition.y /= 3;
    
    float2 noise = fbm2(cloudPosition * 0.001, 6, Time * 0.02, 3.0);
    
    
    float addTime = Time / 100;
    
    if (addTime >= 1.0f)
    {
        addTime = 1.0f;
    }
    
    float3 sunColor = GetAtomColor(LightDirection.xyz) * addTime; //‰_‚ÌF‚ğ‘å‹C‚ÌF‚É‡‚í‚¹‚é
	
    float cloud = saturate(noise + 0.001);
	
    float3 skyColor = output.Emission.rgb = lerp(float3(0.0, 0.0, 1.0),
												 float3(1.0, 1.0, 1.0),
												 cloud);

    output.Emission.rgb = lerp(float3(1.0, 1.0, 1.0),
							   skyColor,
							   saturate(eyeVec.y * 20.0));

    output.Emission.a = 1.0;
    
    
   //ƒ~[U—
    float dle = dot(LightDirection.xyz, eyeVec);
    float g = 0.990f;
    float g2 = g * g;
    float miePhase = 1.5f * ((1.0 + g2) / (2.0 + g2)) * (1.0 + dle * dle) / pow((1.0 + g2 - 2.0 * g * dle), 0.5);
	
    miePhase += step(0.99998, dle) * 10; //‘¾—z’¼ÚŒõ
	
    output.Emission.rgb += miePhase * sunColor;

    return output;
}
