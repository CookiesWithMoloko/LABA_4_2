#include "WebSitesManager.h"

void WebSitesManager::Add(string url)
{
	auto t = gcnew WebSite(url);
	if (!sites_->Contains(t))
		sites_->Add(t);
}

array<WebSite^>^ WebSitesManager::FilterByProtocol(string value)
{
	auto result = gcnew List<WebSite^>();
	for each (auto t in sites_)
		if (t->Protocol == value)
			result->Add(t);
	return result->ToArray();
}

array<WebSite^>^ WebSitesManager::FilterByHost(string value)
{
	auto result = gcnew List<WebSite^>();
	for each (auto t in sites_)
		if (t->Host == value)
			result->Add(t);
	return result->ToArray();
}

array<WebSite^>^ WebSitesManager::FilterByDirectory(string value)
{
	auto result = gcnew List<WebSite^>();
	for each (auto t in sites_)
		if (t->Directory == value)
			result->Add(t);
	return result->ToArray();
}
