#include "Common.hlsl"

PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output;
    
    float2 texCoord = input.TexCoord;;
    
    //ディストーション
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

    //クロマチックアベレーション
    if (isChromaticAberration)
    {
        baseColor.r = TextureBaseColor.Sample(Sampler, texCoord + float2(ChromaticAberration.r, 0.0)).r;
        baseColor.g = TextureBaseColor.Sample(Sampler, texCoord + float2(ChromaticAberration.g, 0.0)).g;
        baseColor.b = TextureBaseColor.Sample(Sampler, texCoord + float2(ChromaticAberration.b, 0.0)).b;
    }
    
    //輝度変更
    baseColor.rgb *= 1.0f;
    
    //モノクロ
    if (isGrayScale)
    {
        float gray;
        gray = GrayScale.r * baseColor.r + GrayScale.g * baseColor.g + GrayScale.b * baseColor.b;
    
        baseColor.rgb = gray;
    }
    
    //セピア
    if (isSepia)
    {
        float3 sepia;
        
        float3 sepiaCol = float3(Sepia.r, Sepia.g, Sepia.b);
        
        sepia = baseColor.rgb * sepiaCol;

        baseColor.rgb = sepia.rgb;
    }
   
    //トーンマッピング
    baseColor.rgb = baseColor.rgb / (1.0 + baseColor.rgb);
    
    //ガンマ補正
    baseColor.rgb = pow(baseColor.rgb, 1.0 / Gamma);
    
    output.Color.rgb = baseColor.rgb;
    output.Color.a = 1.0f;
    
    return output;
}

