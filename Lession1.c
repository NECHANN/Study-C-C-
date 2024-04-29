//Mã số sv: 23110080
//Tác giả: Nguyen Thai Binh
//Ngày cập nhật cuối: 26/04/2024

#include<bits/stdc++.h>
#include <fstream>
using namespace std;

#define Max 20

typedef struct POS
{
    int a; // dong
    // cot
    int b;
};

bool docfile (char *fname[], int a[][Max], int &n);
int thamlam (int a[][Max], int n, POS t[], int &d);

// t luu những vị trí đi qua
// d độ dài đường đi

int thamlam (int a[][Max], int n, POS t[], int &d){
    int tongcd = 0;
    d = 0; 
    POS c;
    c.a = c.b = 0;
    t[d++] = c;
    do {
        // truong hop tram bien phai
        if (c.b == n-1){
            while (c.a <n-1){
                c.a++;
                tongcd += a[c.a][c.b];
                t[d++] = c;
            }
        }
        else if (c.a == n-1) {// cham bien duoi
            while (c.a <n-1){
                c.b++;
                tongcd += a[c.a][c.b];
                t[d++] = c;
            }
        }
        else { // chua cham bien
            // xet vi tri tim min
            POS n;
            n.a = c.a;
            n.b = c.b + 1; // o ben phai
            if(a[n.a][n.b] > a[c.a +1][c.b]){
                n.a = c.a + 1;
                n.b = c.b; 
            }
            if(a[n.a][n.b] > a[c.a +1][c.b+1]){
                n.a = c.a + 1;
                n.b = c.b + 1; 
            }
            // cap nhat duong di
            c = n;
            tongcd += a[c.a][c.b];
            t[d++] = c;
        }
    }while (!(c.a == n -1 && c.b == n-1));
    return tongcd;
}
void changeUser(int user{
    printf("User Changed")
    user++;
}
int main (){
    int a[Max][Max];
    int n;
    POS t[2 * Max];
    int d;
    int tong;
    int count;
    count = 5;
    changeUser(count)
    if (!docfile("D:\\c++\\KTLT\\INPUT.TXT", a, n)) {
		cout << "Loi doc file!\n";
		return -1;
	}
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    tong = thamlam(a,n,t,d);
    cout << "tong cac so tren duong di:" << tong << endl;
    for (int i=0; i<d; i++){
        cout << "(" << t[i].a << ", " << t[i].b << ")-->";
    }
    cout << endl;
    return 0;
}
