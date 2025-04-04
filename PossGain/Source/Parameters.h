#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

struct Parameters {
    void add(juce::AudioProcessor& processor) const {
        processor.addParameter(this->gain);
        processor.addParameter(this->enable);
    }

    // Raw pointers. They will be owned by either the processor or the APVTS (if
    // you use it)
    juce::AudioParameterFloat* gain =
        new juce::AudioParameterFloat({"Gain", 1}, "Gain", 0.f, 1.f, 0.5f);

    juce::AudioParameterBool* enable =
        new juce::AudioParameterBool({"Enable", 1}, "Enable", true);
};
