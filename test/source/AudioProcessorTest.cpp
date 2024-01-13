#include <GainSlider/PluginProcessor.h>
#include <gtest/gtest.h>

namespace audio_plugin_test
{
TEST(PluginProcessor, Foo)
{
  audio_plugin::PluginProcessor processor{};
  ASSERT_FALSE(true);
}
}  // namespace audio_plugin_test