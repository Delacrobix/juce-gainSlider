#include "GainSlider/PluginEditor.h"

#include "GainSlider/PluginProcessor.h"

namespace audio_plugin
{

PluginEditor::PluginEditor(PluginProcessor &p) : AudioProcessorEditor(&p), processorRef(p)
{
  juce::ignoreUnused(processorRef);

  setSize(200, 400);

  gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
  gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
  gainSlider.setRange(-48.0, 0);
  gainSlider.setValue(-1.0);
  gainSlider.addListener(this);

  addAndMakeVisible(gainSlider);
}

PluginEditor::~PluginEditor() {}

void PluginEditor::paint(juce::Graphics &g)
{
  // (Our component is opaque, so we must completely fill the background with a solid colour)
  g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void PluginEditor::resized()
{
  gainSlider.setBounds(getLocalBounds());
}

void PluginEditor::sliderValueChanged(juce::Slider *slider)
{
  if (slider == &gainSlider)
  {
    // Logarithmic gain
    processorRef.rawValue = pow(10, gainSlider.getValue() / 20);
  }
}
}  // namespace audio_plugin