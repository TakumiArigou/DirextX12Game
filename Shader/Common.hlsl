

cbuffer EnvConstantBuffer : register(b0)
{
    float4      LightDirection;
    float4      LightColor;
};

cbuffer CameraConstantBuffer : register(b1)
{
    float4x4    View;
    float4x4    Projection;
    float4      CameraPosition;
            
    float4 GrayScale;
    float4 Sepia;
    float4 ChromaticAberration;
    float2 Distorsion;
    float Gamma;
    
    float Time;
    
    int isGrayScale;
    int isSepia;
    int isDistorsion;
    int isChromaticAberration;
};

cbuffer ObjectConstantBuffer : register(b2)
{
    float4x4    World;
    float4      Field;
    float4      Water;
};

cbuffer SubsetConstantBuffer : register(b3)
{
    struct MATERIAL
    {
        float4 BaseColor;
        float4 EmissionColor;
        float Metallic;
        float Specular;
        float Roughness;
        float NormalWeight;
    } Material;
};

struct VS_INPUT
{
    float3 Position : POSITION;
    float3 Normal   : NORMAL;
    float2 TexCoord : TEXCOORD;
    float4 Color    : COLOR;
    float3 Material : MATERIAL;
};


struct PS_INPUT
{
    float4 Position       : SV_Position;
    float4 WorldPosition  : POSITION;
    float4 Normal         : NORMAL;
    float2 TexCoord       : TEXCOORD;
    float4 Color          : COLOR;
    float4 Material       : MATERIAL;
};


struct PS_OUTPUT
{
    float4 Color : SV_TARGET0;
};


struct PS_OUTPUT_GEOMETRY
{
    float4 Color : SV_TARGET0;
    float4 Normal : SV_TARGET1;
    float4 Position : SV_TARGET2;
    float4 Material : SV_TARGET3;
    float4 Emission : SV_TARGET4;
};



Texture2D<float4> TextureBaseColor : register(t0);
Texture2D<float4> TextureNormal: register(t1);
Texture2D<float4> TexturePosition : register(t2);
Texture2D<float4> TextureMaterial : register(t3);
Texture2D<float4> TextureEmission : register(t4);

SamplerState Sampler : register(s0);

static float PI = 3.141592653589;


//ÉåÉCÉäÅ[éUóêÇ≈ëÂãCêFÇéZèo
float3 GetAtomColor(float3 EyeVector)
{
    EyeVector.y = saturate(EyeVector.y);
    
    float3 sunLight = LightColor;
    float3 wavelength = float3(0.630, 0.532, 0.467); //RGBîgí∑
    float3 wavelength4inv = 1.0 / pow(wavelength, 4);
    
    float dle = dot(LightDirection.xyz, EyeVector);
    
    float atomThicknessRatio = 0.05; //ëÂãCÇÃå˙Ç≥
    float atomDensityEye = atomThicknessRatio + pow(1.0 - EyeVector.y, 10) * (1.0 - atomThicknessRatio);
    float atomDensityLight = atomThicknessRatio + pow(1.0 - LightDirection.y, 9) * (1.0 - atomThicknessRatio);
    float3 scatteringLight = sunLight * exp(-atomDensityLight * atomDensityEye * wavelength4inv * 0.5);
    float rayleighPhese = (0.5 + dle * dle);
    
    float3 atomColor = scatteringLight * atomDensityEye * wavelength4inv * rayleighPhese * 0.03;
    
    return atomColor;
}


float3 GetAtomColorWater(float3 EyeVector)
{
    EyeVector.y = saturate(EyeVector.y);
    
    float3 sunLight = LightColor;
    float3 wavelength = float3(0.630, 0.532, 0.467); //RGBîgí∑
    float3 wavelength4inv = 1.0 / pow(wavelength, 4);
    
    float dle = dot(LightDirection.xyz, EyeVector);
    
    float atomThicknessRatio = 0.1; //ëÂãCÇÃå˙Ç≥
    float atomDensityEye = atomThicknessRatio + pow(1.0 - EyeVector.y, 10) * (1.0 - atomThicknessRatio);
    float atomDensityLight = atomThicknessRatio + pow(1.0 - LightDirection.y, 9) * (1.0 - atomThicknessRatio);
    float3 scatteringLight = sunLight * exp(-atomDensityLight * atomDensityEye * wavelength4inv * 0.5);
    float rayleighPhese = (0.5 + dle * dle);
    
    float3 atomColor = scatteringLight * atomDensityEye * wavelength4inv * rayleighPhese * 0.03;
    
    return atomColor;
}