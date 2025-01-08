#pragma once

#include "OBB.h"

class OBBManager {
public:
    // 2‚Â‚ÌOBB‚ÌÕ“Ë”»’è
    bool ColOBBs(OBB& obb1, OBB& obb2);

private:

    float LenSegOnSeparateAxis(XMVECTOR* Sep, XMVECTOR* e1, XMVECTOR* e2, XMVECTOR* e3 = nullptr);
};