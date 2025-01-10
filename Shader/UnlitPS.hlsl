#include "Common.hlsl"

PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output;
    
    float4 color = Material.BaseColor;
    
    output.Color = TextureBaseColor.Sample(Sampler, input.TexCoord);
   
    output.Color.rgb *= color.rgb;
    
    if (output.Color.a <= 0.5)
    {
        discard;
    }
    
    return output;
}