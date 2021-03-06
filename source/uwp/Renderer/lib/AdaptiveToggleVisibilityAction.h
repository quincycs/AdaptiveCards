#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "Enums.h"
#include "ToggleVisibilityAction.h"
#include "AdaptiveActionElement.h"

namespace AdaptiveNamespace
{
    class DECLSPEC_UUID("32114ce2-7e10-4f7f-8225-bfd661c6794c") AdaptiveToggleVisibilityAction
        : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
                                              ABI::AdaptiveNamespace::IAdaptiveToggleVisibility,
                                              ABI::AdaptiveNamespace::IAdaptiveActionElement,
                                              Microsoft::WRL::CloakedIid<ITypePeek>,
                                              Microsoft::WRL::CloakedIid<AdaptiveNamespace::AdaptiveActionElementBase>>
    {
        AdaptiveRuntime(AdaptiveToggleVisibilityAction);

    public:
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(const std::shared_ptr<AdaptiveSharedNamespace::ToggleVisibilityAction>& sharedToggleVisibilityAction);

        // IAdaptiveToggleVisibilityAction
        IFACEMETHODIMP get_TargetElements(
            _COM_Outptr_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveToggleVisibilityTarget*>** facts);

        // IAdaptiveActionElement
        IFACEMETHODIMP get_ActionType(_Out_ ABI::AdaptiveNamespace::ActionType* actionType);
        IFACEMETHODIMP get_ActionTypeString(_Outptr_ HSTRING* value)
        {
            return AdaptiveActionElementBase::get_ActionTypeString(value);
        }

        IFACEMETHODIMP get_Title(_Outptr_ HSTRING* title) { return AdaptiveActionElementBase::get_Title(title); }
        IFACEMETHODIMP put_Title(_In_ HSTRING title) { return AdaptiveActionElementBase::put_Title(title); }

        IFACEMETHODIMP get_Id(_Outptr_ HSTRING* id) { return AdaptiveActionElementBase::get_Id(id); }
        IFACEMETHODIMP put_Id(_In_ HSTRING id) { return AdaptiveActionElementBase::put_Id(id); }

        IFACEMETHODIMP get_IconUrl(_Outptr_ HSTRING* iconUrl)
        {
            return AdaptiveActionElementBase::get_IconUrl(iconUrl);
        }
        IFACEMETHODIMP put_IconUrl(_In_ HSTRING iconUrl) { return AdaptiveActionElementBase::put_IconUrl(iconUrl); }

        IFACEMETHODIMP get_Sentiment(_Out_ ABI::AdaptiveNamespace::Sentiment* sentiment)
        {
            return AdaptiveActionElementBase::get_Sentiment(sentiment);
        }
        IFACEMETHODIMP put_Sentiment(ABI::AdaptiveNamespace::Sentiment sentiment)
        {
            return AdaptiveActionElementBase::put_Sentiment(sentiment);
        }

        IFACEMETHODIMP get_AdditionalProperties(_COM_Outptr_ ABI::Windows::Data::Json::IJsonObject** result)
        {
            return AdaptiveActionElementBase::get_AdditionalProperties(result);
        }
        IFACEMETHODIMP put_AdditionalProperties(_In_ ABI::Windows::Data::Json::IJsonObject* value)
        {
            return AdaptiveActionElementBase::put_AdditionalProperties(value);
        }

        IFACEMETHODIMP ToJson(_COM_Outptr_ ABI::Windows::Data::Json::IJsonObject** result)
        {
            return AdaptiveActionElementBase::ToJson(result);
        }

        virtual HRESULT GetSharedModel(std::shared_ptr<AdaptiveSharedNamespace::BaseActionElement>& sharedModel) override;

        // ITypePeek method
        void* PeekAt(REFIID riid) override { return PeekHelper(riid, this); }

    private:
        Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveToggleVisibilityTarget*>> m_targetElements;
    };

    ActivatableClass(AdaptiveToggleVisibilityAction);
}
