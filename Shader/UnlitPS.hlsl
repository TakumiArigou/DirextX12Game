#include "Common.hlsl"

PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output;
    
    output.Color = TextureBaseColor.Sample(Sampler, input.TexCoord);
   
    if (output.Color.a <= 0.5)
    {
        discard;
    }
    
    return output;
}