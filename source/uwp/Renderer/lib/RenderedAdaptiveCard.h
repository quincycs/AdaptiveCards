#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "util.h"
#include "InputValue.h"
#include "AdaptiveInputs.h"

namespace AdaptiveNamespace
{
    class RenderedAdaptiveCard
        : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
                                              Microsoft::WRL::Implements<ABI::AdaptiveNamespace::IRenderedAdaptiveCard>>
    {
        AdaptiveRuntime(RenderedAdaptiveCard);

    public:
        RenderedAdaptiveCard();

        HRESULT RuntimeClassInitialize();
        HRESULT RuntimeClassInitialize(
            _In_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveError*>* errors,
            _In_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveWarning*>* warnings);

        // IRenderedAdaptiveCard
        IFACEMETHODIMP get_OriginatingCard(_COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveCard** value);
        IFACEMETHODIMP get_FrameworkElement(_COM_Outptr_ ABI::Windows::UI::Xaml::IFrameworkElement** value);
        IFACEMETHODIMP get_UserInputs(_COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveInputs** value);
        IFACEMETHODIMP add_Action(_In_ ABI::Windows::Foundation::ITypedEventHandler<ABI::AdaptiveNamespace::RenderedAdaptiveCard*,
                                                                                    ABI::AdaptiveNamespace::AdaptiveActionEventArgs*>* handler,
                                  _Out_ EventRegistrationToken* token);
        IFACEMETHODIMP remove_Action(EventRegistrationToken token);

        IFACEMETHODIMP add_MediaClicked(
            _In_ ABI::Windows::Foundation::ITypedEventHandler<ABI::AdaptiveNamespace::RenderedAdaptiveCard*, ABI::AdaptiveNamespace::AdaptiveMediaEventArgs*>* handler,
            _Out_ EventRegistrationToken* token);
        IFACEMETHODIMP remove_MediaClicked(EventRegistrationToken token);

        IFACEMETHODIMP get_Errors(_COM_Outptr_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveError*>** value);
        IFACEMETHODIMP get_Warnings(
            _COM_Outptr_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveWarning*>** value);

        HRESULT AddInputValue(_In_ ABI::AdaptiveNamespace::IAdaptiveInputValue* inputValue);
        void SetFrameworkElement(_In_ ABI::Windows::UI::Xaml::IFrameworkElement* value);
        void SetOriginatingCard(_In_ ABI::AdaptiveNamespace::IAdaptiveCard* value);
        HRESULT SendActionEvent(_In_ ABI::AdaptiveNamespace::IAdaptiveActionElement* eventArgs);
        HRESULT SendMediaClickedEvent(_In_ ABI::AdaptiveNamespace::IAdaptiveMedia* eventArgs);

    private:
        Microsoft::WRL::ComPtr<ABI::AdaptiveNamespace::IAdaptiveCard> m_originatingCard;
        Microsoft::WRL::ComPtr<AdaptiveNamespace::AdaptiveInputs> m_inputs;
        Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IFrameworkElement> m_frameworkElement;
        Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveError*>> m_errors;
        Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveWarning*>> m_warnings;
        std::shared_ptr<ActionEventSource> m_actionEvents;
        std::shared_ptr<MediaEventSource> m_mediaClickedEvents;
    };

    ActivatableClass(RenderedAdaptiveCard);
}
