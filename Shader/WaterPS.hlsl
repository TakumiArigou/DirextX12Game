#include "Common.hlsl"
#include "Noise.hlsl"


PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output;


	//�@���Z�o
    float dx = GetWaterHeight(input.WorldPosition.xz + float2(0.1f, 0.0f), Water.y, Time, Water.x)
	         - GetWaterHeight(input.WorldPosition.xz - float2(0.1f, 0.01), Water.y, Time, Water.x);
	
    float dz = GetWaterHeight(input.WorldPosition.xz + float2(0.0f, 0.1f), Water.y, Time, Water.x)
			 - GetWaterHeight(input.WorldPosition.xz - float2(0.0f, 0.1f), Water.y, Time, Water.x);
	
    float3 normal = float3(-dx, 1.0f, -dz);
    
    normal = normalize(normal);
    
    //�n�[�t�����o�[�g
    //float3 normal = normalize(input.Normal.rgb);
    //output.Color.rgb = saturate(dot(LightDirection.xyz, normal.xyz) * 0.5 + 0.5);
    //output.Color.rgb *= fbm2(input.WorldPosition.xz * 0.1, 8, Time);
    
    //�����x�N�g������
    float3 eyeVec = input.WorldPosition.xyz - CameraPosition.xyz;
    eyeVec = normalize(eyeVec);
    
    //���˃x�N�g��
    float3 refVec = reflect(eyeVec, normal);
    
    //�t���l�����˗�(Schlick�ߎ���)
    float f0 = 0.02;
    float d = saturate(dot(-eyeVec, normal));
    float fresnel = f0 + (1.0 - f0) * pow((1.0 - d), 5.0);
    
    float3 atomColor = GetAtomColorWater(refVec);
    
    output.Color.rgb = atomColor; //��̔��ːF(��̐F�ɍ��킹��)
    output.Color.a = fresnel;

    return output;
}
