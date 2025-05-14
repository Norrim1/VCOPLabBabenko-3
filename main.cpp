#include <iostream>
#include <interface.h>

using namespace std;

int main() {
    cout<<"Client: hello, world!"<<endl;
    cout<<"\nClient: get pointer to IUnknown"<<endl;
    IUnknown* pIUnknown = CreateInstance();
    cout<<"\nClient: get pointer to IX"<<endl;
    IX* pIX = NULL;
    HRESULT hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
    if (SUCCEEDED(hr)) {
        cout<<"Client: IX received successfully"<<endl;
        pIX->Fx();
    }
    cout<<"\nClient: get pointer to IY"<<endl;
    IY* pIY = NULL;
    hr = pIUnknown->QueryInterface(IID_IY, (void**)&pIY);
    if (SUCCEEDED(hr)) {
        cout<<"Client: IY received successfully"<<endl;
        pIY->Fy();
    }
    cout<<"\nClient: get unsupported interface"<<endl;
    IZ* pIZ = NULL;
    hr = pIUnknown->QueryInterface(IID_IZ, (void**)&pIZ);
    if (SUCCEEDED(hr)) {
        cout<<"Client: interface IZ get successfully"<<endl;
    } else {
        cout<<"Client: Can not get interface IZ"<<endl;
    }
    cout <<"\nClient: get pointer to IY through IX"<< endl;
    pIY = NULL;
    hr = pIX->QueryInterface(IID_IY, (void**)&pIY);
    if (SUCCEEDED(hr)) {
        cout<<"Client: IY through IX received successfully"<<endl;
        pIY->Fy();
    } else {
        cout<<"Client: Can not get interface IY through IX"<<endl;
    }
    delete pIUnknown;

    return 0;
}
