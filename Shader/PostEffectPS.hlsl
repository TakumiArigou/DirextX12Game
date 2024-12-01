#include "Common.hlsl"

PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output;
    
    float2 texCoord = input.TexCoord;;
    
    //�f�B�X�g�[�V����
    if (isDistorsion)
    {
        float2 center = float2(0.5f, 0.5f);
        float2 offset = input.TexCoord - center;
        float r = length(offset);
        float2 distorsion;
        
        distorsion = offset * (Distorsion.y + pow(r, 2.0f) * Distorsion.x);
        
        texCoord = center + distorsion;
    }
 
    
    float4 baseColor = TextureBaseColor.Sample(Sampler, texCoord).rgba;

    //�N���}�`�b�N�A�x���[�V����
    if (isChromaticAberration)
    {
        baseColor.r = TextureBaseColor.Sample(Sampler, texCoord + float2(ChromaticAberration.r, 0.0)).r;
        baseColor.g = TextureBaseColor.Sample(Sampler, texCoord + float2(ChromaticAberration.g, 0.0)).g;
        baseColor.b = TextureBaseColor.Sample(Sampler, texCoord + float2(ChromaticAberration.b, 0.0)).b;
    }
    
    //�P�x�ύX
    baseColor.rgb *= 1.0f;
    
    //���m�N��
    if (isGrayScale)
    {
        float gray;
        gray = GrayScale.r * baseColor.r + GrayScale.g * baseColor.g + GrayScale.b * baseColor.b;
    
        baseColor.rgb = gray;
    }
    
    //�Z�s�A
    if (isSepia)
    {
        float3 sepia;
        
        float3 sepiaCol = float3(Sepia.r, Sepia.g, Sepia.b);
        
        sepia = baseColor.rgb * sepiaCol;

        baseColor.rgb = sepia.rgb;
    }
   
    //�g�[���}�b�s���O
    baseColor.rgb = baseColor.rgb / (1.0 + baseColor.rgb);
    
    //�K���}�␳
    baseColor.rgb = pow(baseColor.rgb, 1.0 / Gamma);
    
    output.Color.rgb = baseColor.rgb;
    output.Color.a = 1.0f;
    
    return output;
}

