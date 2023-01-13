//#include <iostream>
//#include <vector>
//#include <cpprest/http_client.h>
//#include <cpprest/filestream.h>
//#include <cpprest/json.h>
//using namespace std;
//using namespace utility;
//using namespace web;
//using namespace web::http;
//using namespace web::http::client;
//using namespace web::json;
//using namespace concurrency::streams;
//
//void printWstring(wstring wstr) {
//	wstring str;
//	str.assign(wstr.begin(), wstr.end());
//	wcout << str << endl;
//}
//
//void HttpRequest()
//{
//	wstring url = U("https://daum.net");
//	wcout << url << endl;
//	http_client client(url);
//	http_request get_req(methods::GET);
//
//	/*
//		HTTP 요청 메서드
//
//		CREATE
//		READ
//		UPDATE
//		DELETE
//		-----------
//		GET -> READ
//		POST -> CREATE
//		PUT -> UPDATE (for all data)
//		PATCH -> UPDATE (for partial data)
//		DELETE
//
//		GET /movies
//		GET /movies/1534
//		POST /movies
//				{movieName : "~~~~", releasedDate : "~~~~|~~|~~"} <- JSON 객체 형식이 아님에 주목
//		PATCH /movies/1534
//				{movieName : "~~~~", releasedDate : "~~~~|~~|~~"}
//		DELETE /moives/1534
//	*/
//
//	auto get_resp = client.request(get_req).get();
//	cout << get_resp.status_code() << " : sync request" << endl; // <- 결과 상태 확인
//	// 만약, json 이 아니라 string 으로 처리하고 싶으면(HTML 문서 크롤링 등) 다음을 대신 사용
//	auto html = get_resp.extract_string(true).get();
//	printWstring(html);
//}
//
//int main()
//{	// REST API : HTTP 프로토콜로 JSON을 주고받는 원칙
//	// http://apis.data.go.kr/1352000/ODMS_COVID_05/callCovid05Api
//	// 유니코드 (windows only) 설정
//	wcout.imbue(locale("kor"));
//	HttpRequest();
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>

using namespace std;
using namespace utility;
using namespace utility::conversions;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace web::json;
using namespace concurrency::streams;

string url_encode(string origin) {
	string ret = "";
	for (int index = 0; index < origin.size(); index++)
	{
		if (!(origin[index] & 0x80)) {
			ret += origin[index];
			continue;
		} // ascii code
		unsigned char el = origin[index];
		char temp[4];
		sprintf(temp, "%%%2X", el);
		ret += temp;
	}
	return ret;
}

void HttpRequest()
{
	wstring search_gu, search_dong;
	cout << "어디 날씨가 궁금해? XX구 XX동으로 입력하자" << endl;
	wcin >> search_gu >> search_dong;
	wstring search = search_gu + U("+") + search_dong + U("+") + U("날씨");

	wstring url = U("https://search.naver.com/search.naver?sm=tab_hty.top&where=nexearch&query=");
	url += search;

	string utf_8_url = url_encode(to_utf8string(url));
	wstring path;
	path.assign(utf_8_url.begin(), utf_8_url.end());
	http_client client(path);
	http_request get_req(methods::GET);
	auto get_resp = client.request(get_req).get();
	// cout << get_resp.status_code() << " : sync request" << endl;
	auto html = get_resp.extract_string(true).get();
	wstring str;
	str.assign(html.begin(), html.end());
	
	wstring find_st = U("현재 온도</span>");
	wstring find_en = U("<span class=\"celsius\">");
	auto index_st = html.find(find_st);
	auto index_en = html.find(find_en);
	wstring celsius;
	celsius.assign(html.begin() + index_st + find_st.size(), html.begin() + index_en);
	wcout << U("현재 온도 : ") << celsius << endl;
}
int main()
{
	wcin.imbue(locale("kor"));
	wcout.imbue(locale("kor"));
	HttpRequest();
	return 0;
}
