#pragma once
#include "WebSite.h"
using System::Collections::Generic::List;
typedef System::String^ string;
ref class WebSitesManager
{
	List<WebSite^>^ sites_;
public:
	WebSitesManager()
	{
		sites_ = gcnew List<WebSite^>();
	}
	property array<WebSite^>^ WebSites
	{
		array<WebSite^>^ get() { return sites_->ToArray(); }
	}
	property array<string>^ Protocols
	{
		array<string>^ get()
		{
			auto r = gcnew List<string>();
			for each (auto t in sites_)
				if (!r->Contains(t->Protocol))
					r->Add(t->Protocol);
			return r->ToArray();
		}
	}
	property array<string>^ Hosts
	{
		array<string>^ get()
		{
			auto r = gcnew List<string>();
			for each (auto t in sites_)
				if (!r->Contains(t->Host))
					r->Add(t->Host);
			return r->ToArray();
		}
	}
	property array<string>^ Directories
	{
		array<string>^ get()
		{
			auto r = gcnew List<string>();
			for each (auto t in sites_)
				if (!r->Contains(t->Directory))
					r->Add(t->Directory);
			return r->ToArray();
		}
	}
	void Add(string url);
	array<WebSite^>^ FilterByProtocol(string value);
	array<WebSite^>^ FilterByHost(string value);
	array<WebSite^>^ FilterByDirectory(string value);

};

