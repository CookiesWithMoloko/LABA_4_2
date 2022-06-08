#pragma once
typedef System::String^ string;
ref class WebSite : System::Object
{
	string protocol_;
	string host_;
	string directory_;

public:
	WebSite(string value)
	{
		int d = value->IndexOf("://");
		protocol_ = value->Substring(0, d);
		value = value->Substring(d + 3, value->Length - 3 - d);
		d = value->IndexOf("/");
		host_ = value->Substring(0,  d);
		directory_ = value->Substring(d + 1, value->Length - d - 1);
	}
	property string Protocol {
		string get() { return protocol_; }
	}
	property string Host {
		string get() { return host_; }
	}
	property string Directory {
		string get() { return directory_; }
	}
	bool Equals(Object^ obj) override
	{
		auto r = (WebSite^)obj;
		return
			r->Host == host_ &&
			r->Directory == directory_ &&
			r->Protocol == protocol_;

	}
	string ToString() override
	{
		return System::String::Format("WebSite(\"{0}://{1}/{2}\")", protocol_, host_, directory_);
	}
};

