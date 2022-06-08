#include "WebSitesManager.h"
#include <assert.h>

void test1()
{
	auto t = gcnew WebSite("https://google.com/");
	assert(t->Directory == "");
	assert(t->Host == "google.com");
	assert(t->Protocol == "https");
}
void test2()
{
	auto t = gcnew WebSitesManager();
	t->Add("https://google.com/");
	t->Add("https://google.com/");
	assert(t->WebSites->Length == 1);
	t->Add("https://yandex.ru/");
	assert(t->Directories->Length == 1);
	assert(t->Protocols->Length == 1);
	assert(t->Hosts->Length == 2);
}

int main()
{
	test1();
	test2();
	return 0;
}
