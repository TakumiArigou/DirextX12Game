#pragma once


class OBB
{
protected:
    XMFLOAT3 m_Pos;                  // 位置
    XMFLOAT3 m_NormaDirect[3];       // 方向ベクトル（3つの軸）
    float m_fLength[3];              // 各軸方向の長さ

public:
    // コンストラクタ
    OBB(const XMFLOAT3& position, const XMFLOAT3& dirX, const XMFLOAT3& dirY, const XMFLOAT3& dirZ, float lenX, float lenY, float lenZ);

    // 指定軸番号の方向ベクトルを取得
    XMFLOAT3 GetDirect(int elem);

    // 指定軸方向の長さを取得
    float GetLen_W(int elem);

    // 位置を取得
    XMFLOAT3 GetPos_W();

    // ベクトルを取得するためのDirectXMath形式のXMVECTOR版の関数
    XMVECTOR GetDirectXM(int elem);
};