#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    /*
    char str[100] = "string";
    string s = "string";

    // quiz # 1 : 문자열의 길이를 찾아라!
    // 구현
    int len = 0;
    int idx = 0;
    while (str[idx] != '\0') {
        len++;
        idx++;
    }
    cout << len << '\n';

    // cstring library
    cout << strlen(str) << '\n';

    // string class (자료형)
    // string.length() : 길이
    cout << s.length();
    */

    /*
    // quiz #2. 두개의 문자열이 동일하면 1 아니면 0을 출력하는 프로그램
    char a[100] = "abc";
    char b[100] = "abc";

    // 두개의 길이가 다르면 둘이 같은 문자열일 수 없다.
    if (strlen(a) != strlen(b))
        cout << 0;
    else {
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] != b[i]) {
                cout << 0;
                return 0;
            }
        }
        cout << 1;
    }

    cout << '\n';

    // cstring -> strcmp
    // string compare
    // a == b : 0
    // a != b : -1->a가 b보다 사전순으로 앞에온다,
    // 또는 1-> a가 b보다 사전순으로 늦게온다
    if (strcmp(a, b) == 0)
        cout << 1;
    else
        cout << 0;

    // string class
    string c = "abc"; // 97 98
    string d = "aac"; // 97 97
    cout << '\n';

    if (c < d)
        cout << 1;
    else
        cout << 0;
    */

    // quiz #3. 두개의 문자열을 결합 -> a에다가 결합

    //char a[100] = "str";
    //char b[100] = "ing"; 

    //// 길이 구하기
    ///*
    //int lena = strlen(a);
    //int lenb = strlen(b); 
    //
    //for (int i = 0; i < lenb; i++) {
    //    a[i+lena] = b[i]; 
    //}
    //a[lena + lenb] = '\0'; 
    //
    //cout << a << '\n';    
    //*/

    //// cstring
    //// strcat -> string concatenate 
    //// strcat(a,b) => b가 a에 결합
    //strcat(a, b);
    //cout << a <<'\n'; 
    //
    //// string class
    //// 연산자 사용 가능 -> 
    //// + = 결합
    //string c = "str";
    //string d = "str"; 
    //c += d; 
    //cout << c;


    // quiz #4. 문자열 복사하기
    // 구현
    //char a[100] = "string";
    //char b[100]; 

    ///*
    //int lena = strlen(a); 
    //for (int i = 0; i < lena; i++) {
    //    b[i] = a[i]; 
    //}
    //b[lena] = '\0'; 
    //cout << b; 
    //*/

    //// cstring
    //// strcpy -> string copy 
    //// strcpy(복사하고자 하는 문자열의 위치, 복사하려고 하는 문자열)
    //strcpy(b, a); 
    //cout << b << '\n';

    //// string class
    //string c = "string";
    //string d;
    //d = c; 
    //cout << d << '\n';


    // quiz5. 부분 복사
    // 2개의 정수 입력 -> 2 6 
    /*
    char a[100] = "string";
    char b[100];
    int st, en;
    cin >> st >> en;

    int idx = 0;
    for (int i = st; i < en; i++) {
        b[idx] = a[i];
        idx++;
    }
    b[idx] = '\0';
    cout << b;
    */

    // cstring
    // 전체 복사 = strcpy
    // 일부분 복사 => 
    // strncpy(복사를 해서 저장할 위치, 복사를 할 위치, 복사를 할 구간 크기)
    /*
    int st, en;
    cin >> st >> en;
    char a[100] = "string";
    char b[100];
    strncpy(b, a + st, en - st);
    b[en-st] = '\0';
    cout << b;
    */

    // string class
    // 부분 문자열을 가져와라! substr()
    // substr(시작위치(index), 구간 크기(index))
    //string c = "string";
    //string d; 
    //int st, en;
    //cin >> st >> en;
    //// 만약 구간 크기가 문자열의 길이를 넘어간다면 -> 알아서 마지막까지로 짤라준다.
    //d = c.substr(st, en - st);
    //cout << d;

    /*
    char s[] = "string";
    int arr[] = { 11, 2, 3, 4, 5 };
    cout << *arr << '\n';
    */

    // quiz. 문자열에서 특정 substring이 등장하는 위치 

    /*
    char a[100] = "string";
    char b[100];
    cin >> b;
    */
    /*
    // a 문자열의 모든 위치에서부터
    for (int i = 0; strlen(a) - strlen(b); i++) {
        // 동일한 문자의 개수
        int cnt = 0;
        // 가능한 b 길이의 모든 위치 확인
        for (int j = 0; j < strlen(b); j++) {
            // 이 구간 내에 모든 문자 구성이 동일한가?
            if (a[i + j] == b[j])
                cnt++;
        }
        // 모든 구간이 동일하다면 cnt == strlen(b)
        if (cnt == strlen(b)) {
            cout << i;
            return 0;
        }
    }*/

    // cstring
    // strstr(A, B) -> pointer를 return
    // -> 찾으려고 하는 문자열이 A에 존재한다면, 처음 찾은 위치를 기준으로 
    // 남은 문자열 전체를 반환
    // cout << strstr(a, b);

    // string class
    // 부분 문자열을 찾을려고 한다. -> find()
    // str.find(내가 찾으려고 하는 substring) -> substring을 찾은 첫 index를 return
    // 만약에 find로 못찾는다면
    // 1. string::npos return 
    // 2. -1로 인식해서 해결
    string a = "stssst";
    string b = "g";
    // 찾을 수 있다면 어떠한 값 
    if (a.find(b) == -1)
        cout << 0;
    // 찾을 수 없다면
    else
        cout << 1;
}