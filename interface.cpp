#include "interface.h"

using namespace std;

const IID IID_IX = {0x32BB8320, 0xB41B, 0x11CF, {0xA6, 0xBB, 0x00, 0x80, 0xC7, 0xB2, 0xD6, 0x82}};
const IID IID_IY = {0x32BB8321, 0xB41B, 0x11CF, {0xA6, 0xBB, 0x00, 0x80, 0xC7, 0xB2, 0xD6, 0x82}};
const IID IID_IZ = {0x32BB8322, 0xB41B, 0x11CF, {0xA6, 0xBB, 0x00, 0x80, 0xC7, 0xB2, 0xD6, 0x82}};
const IID IID_IUnknown = {0x32BB8323, 0xB41B, 0x11CF, {0xA6, 0xBB, 0x00, 0x80, 0xC7, 0xB2, 0xD6, 0x82}};

ULONG __stdcall CA::AddRef() { return 0;}

ULONG __stdcall CA::Release() { return 0;}

HRESULT __stdcall CA::QueryInterface(const IID& iid, void** ppv) {
    if (iid == IID_IUnknown) {
        *ppv = static_cast<IX*>(this);
        cout<<"QueryInterface: get pointer to IUnknown"<<endl;
    }
    else if (iid == IID_IX) {
        *ppv = static_cast<IX*>(this);
        cout<<"QueryInterface: get pointer to IX"<<endl;
    }
    else if (iid == IID_IY) {
        *ppv = static_cast<IY*>(this);
        cout<<"QueryInterface: get pointer to IY"<<endl;
    }
    else {
        *ppv = NULL;
        cout<<"Interface is unavailable"<<endl;
        return E_NOINTERFACE;
    }
    reinterpret_cast<IUnknown*>(*ppv)->AddRef();
    return S_OK;
}

void __stdcall CA::Fx() {cout<<"CA::Fx"<<endl;}
void __stdcall CA::Fy() {cout<<"CA::Fy"<<endl;}

IUnknown* CreateInstance() {
    IUnknown* pI = static_cast<IX*>(new CA);
    pI->AddRef();
    return pI;
};
