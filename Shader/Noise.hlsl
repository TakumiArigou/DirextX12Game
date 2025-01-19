//#include "Common.hlsl"


//2D��1D�^������
float random2(in float2 vec)
{
    return frac(sin(dot(vec.xy, float2(12.9898, 78.233))) * 43758.5453123);
}


//3D��1D�^������
float random3(in float3 vec)
{
    return frac(sin(dot(vec.xyz, float3(12.9898, 78.233, 89.345))) * 43758.5453123);
}


//2D��2D�^������
float random22(in float2 vec)
{
    vec = float2(dot(vec, float2(127.1, 311.7)), dot(vec, float2(269.5, 183.3)));
    
    return frac(sin(vec) * (97.5453123)); //GPU�̏����ɍ��킹���l�ɂ���
    
    //bit���Z�̕������x���ǂ�
}


//3D��3D�^������
float random33(in float3 vec)
{
    vec = float3(dot(vec.xyz, float3(127.1, 311.7, 489.2)),
                 dot(vec.xyz, float3(269.5, 183.3, 729.4)),
                 dot(vec.xyz, float3(423.1, 749.7, 297.4)));
    
    return frac(sin(vec) * (97.5453123)); //GPU�̏����ɍ��킹���l�ɂ���
}


//�{���m�C�}
float voronoi2(in float2 vec)
{
    float2 ivec = floor(vec);
    float2 fvec = frac(vec);

    float value = 1.0;
    
    for (int y = -1; y <= 1; y++)
    {
        for (int x = -1; x <= 1; x++)
        {
            float2 offset = float2(x, y);
            
            float2 position;
            position = random22(ivec + offset);
            
            float dist = distance(position + offset, fvec);

            value = min(value, dist);
        }
    }
    return value;
}


//�o�����[�m�C�Y
float valueNoise2(in float2 vec)
{
    float2 ivec = floor(vec);
    float2 fvec = frac(vec);
    
    float a = random2(ivec + float2(0.0, 0.0));
    float b = random2(ivec + float2(1.0, 0.0));
    float c = random2(ivec + float2(0.0, 1.0));
    float d = random2(ivec + float2(1.0, 1.0));

    //�G���~�[�g���(smoothstep)
    fvec = smoothstep(0.0, 1.0, fvec);
    
    //���`���(lerp)
    return lerp(lerp(a, b, fvec.x), lerp(c, d, fvec.x), fvec.y);
}


//�p�[�����m�C�Y
float perlinNoise2(in float2 vec)
{
    float2 ivec = floor(vec);
    float2 fvec = frac(vec);

    float a = dot(random22(ivec + float2(0.0, 0.0)) * 2.0 - 1.0, fvec - float2(0.0, 0.0));
    float b = dot(random22(ivec + float2(1.0, 0.0)) * 2.0 - 1.0, fvec - float2(1.0, 0.0));
    float c = dot(random22(ivec + float2(0.0, 1.0)) * 2.0 - 1.0, fvec - float2(0.0, 1.0));
    float d = dot(random22(ivec + float2(1.0, 1.0)) * 2.0 - 1.0, fvec - float2(1.0, 1.0));

    fvec = smoothstep(0.0, 1.0, fvec);
    
    return lerp(lerp(a, b, fvec.x), lerp(c, d, fvec.x), fvec.y);
}


//3D�p�[�����m�C�Y
float perlinNoise3(in float3 vec)
{
    float3 ivec = floor(vec);
    float3 fvec = frac(vec);

    float a = dot(random33(ivec + float3(0.0, 0.0, 0.0)) * 2.0 - 1.0, fvec - float3(0.0, 0.0, 0.0));
    float b = dot(random33(ivec + float3(1.0, 0.0, 0.0)) * 2.0 - 1.0, fvec - float3(1.0, 0.0, 0.0));
    float c = dot(random33(ivec + float3(0.0, 1.0, 0.0)) * 2.0 - 1.0, fvec - float3(0.0, 1.0, 0.0));
    float d = dot(random33(ivec + float3(1.0, 1.0, 0.0)) * 2.0 - 1.0, fvec - float3(1.0, 1.0, 0.0));
    
    float e = dot(random33(ivec + float3(0.0, 0.0, 1.0)) * 2.0 - 1.0, fvec - float3(0.0, 0.0, 1.0));
    float f = dot(random33(ivec + float3(1.0, 0.0, 1.0)) * 2.0 - 1.0, fvec - float3(1.0, 0.0, 1.0));
    float g = dot(random33(ivec + float3(0.0, 1.0, 1.0)) * 2.0 - 1.0, fvec - float3(0.0, 1.0, 1.0));
    float h = dot(random33(ivec + float3(1.0, 1.0, 1.0)) * 2.0 - 1.0, fvec - float3(1.0, 1.0, 1.0));

    fvec = smoothstep(0.0, 1.0, fvec);
    
    float v1 = lerp(lerp(a, b, fvec.x), lerp(c, d, fvec.x), fvec.y);
    float v2 = lerp(lerp(e, f, fvec.x), lerp(g, h, fvec.x), fvec.y);
    
    return lerp(v1, v2, fvec.z);
}


//FBM(�t���N�^���p�[�����m�C�Y)
float fbm2(in float2 vec, in int octave, in float2 offset = 0.0, in float vecValue = 2.0)
{
    float value = 0.0;
    float amplitude = 1.0;
    
    vec.y += Time;
    
    for (int i = 0; i < octave; i++)
    {
        value += amplitude * perlinNoise2(vec + offset);
        vec *= vecValue;
        amplitude *= 0.5;
    }
    
    return value;
}

//�t�F�[���h�pFBM
float fbm2field(in float2 vec, in int octave)
{
    vec.y += Time / 5;
    
    float value = 0.0;
    float amplitude = 1.0;
    
    for (int i = 0; i < octave; i++)
    {
        value += amplitude * (perlinNoise2(vec)) - 0.1; //abs()�F��Βl�ɕϊ�����֐�(�Ⴆ��-1��1�ɂȂ�)
        vec *= 2.0;
        amplitude *= 0.5;
    }
    
    return value;
}

//���pFBM
float fbm2water(in float2 vec, in int octave, in float2 offset = 0.0, in float vecValue = 2.0)
{
    float value = 0.0;
    float amplitude = 1.0;
    
    vec.y += Time * 2;
    
    for (int i = 0; i < octave; i++)
    {
        value += amplitude * perlinNoise2(vec + offset) + 7;
        vec *= vecValue;
        amplitude *= 0.5;
    }
    
    return value;
}

//3DFBM(�t���N�^���p�[�����m�C�Y)
float fbm3(in float3 vec, int octave)
{
    float value = 0.0;
    float amplitude = 1.0;
    
    for (int i = 0; i < octave; i++)
    {
        value += amplitude * perlinNoise3(vec);
        vec *= 2.0;
        amplitude *= 0.5;
    }
    
    return value;
}

//FBM ABS(�A�u�X�g���N�g)
float fbm2abs(in float2 vec, in int octave)
{
    vec.y += Time / 5;
    
    float value = 0.0;
    float amplitude = 1.0;
    
    for (int i = 0; i < octave; i++)
    {
        value += amplitude * (perlinNoise2(vec)) - 0.1; //abs()�F��Βl�ɕϊ�����֐�(�Ⴆ��-1��1�ɂȂ�)
        vec *= 2.0;
        amplitude *= 0.5;
    }
    
    return value;
}

//�t�B�[���h�̍���
float GetFieldHeight(in float2 Position, in int Octave, in float Hight, in float Mesh)
{
    return fbm2field(Position * Mesh, Octave) * Hight;
}

//���̍���
float GetWaterHeight(in float2 Position, in int Octave, in float offset, in float Hight = 3.0f)
{
    return fbm2water(Position * 0.02, Octave, offset) * Hight;
}