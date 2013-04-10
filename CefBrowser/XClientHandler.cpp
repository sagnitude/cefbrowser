#include "StdAfx.h"
#include "XClientHandler.h"


#include "XGlobal.h"


XClientHandler::XClientHandler(void)
{
}

XClientHandler::~XClientHandler(void)
{
}


bool XClientHandler::OnBeforePopup(CefRefPtr<CefBrowser> browser,
                                  CefRefPtr<CefFrame> frame,
                                  const CefString& target_url,
                                  const CefString& target_frame_name,
                                  const CefPopupFeatures& popupFeatures,
                                  CefWindowInfo& windowInfo,
                                  CefRefPtr<CefClient>& client,
                                  CefBrowserSettings& settings,
                                  bool* no_javascript_access)
{
    if (browser->GetHost()->IsWindowRenderingDisabled()) {
        // Cancel popups in off-screen rendering mode.
        return true;
    }

    XGlobal::inst().TabHost.AddTab(browser, &windowInfo);

    return false;
}

void XClientHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
    XGlobal::inst().TabHost.AddTab(browser, NULL);
}

bool XClientHandler::DoClose(CefRefPtr<CefBrowser> browser)
{
    return false;
}

void XClientHandler::OnBeforeClose(CefRefPtr<CefBrowser> browser)
{
    ;
}

bool XClientHandler::GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect)
{
    return false;
}

void XClientHandler::OnPopupShow(CefRefPtr<CefBrowser> browser, bool show)
{
}

void XClientHandler::OnPopupSize(CefRefPtr<CefBrowser> browser, const CefRect& rect)
{
}

void XClientHandler::OnPaint(CefRefPtr<CefBrowser> browser,
                     PaintElementType type,
                     const RectList& dirtyRects,
                     const void* buffer,
                     int width,
                     int height)
{
    ;
}

//////////////////////////////////////////////////////////////////////////
// CefDisplayHandler methods
void XClientHandler::OnAddressChange(CefRefPtr<CefBrowser> browser,
                             CefRefPtr<CefFrame> frame,
                             const CefString& url)
{
    if(!frame->IsMain())
        return;

    XGlobal::inst().TabHost.OnAddressChange(browser, url.c_str());
}

void XClientHandler::OnTitleChange(CefRefPtr<CefBrowser> browser,
                           const CefString& title)
{
    XGlobal::inst().TabHost.OnTitleChange(browser, title.c_str());
}