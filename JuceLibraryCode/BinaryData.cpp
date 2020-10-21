/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== Makefile.am ==================
static const unsigned char temp_binary_data_0[] =
"noinst_LIBRARIES = libmopo.a\r\n"
"libmopo_a_SOURCES = alias.cpp \\\r\n"
"                    alias.h \\\r\n"
"                    arpeggiator.cpp \\\r\n"
"                    arpeggiator.h \\\r\n"
"                    bit_crush.cpp \\\r\n"
"                    bit_crush.h \\\r\n"
"                    bypass_router.cpp \\\r\n"
"                    bypass_router.h \\\r\n"
"                    common.h \\\r\n"
"                    delay.cpp \\\r\n"
"                    delay.h \\\r\n"
"                    distortion.cpp \\\r\n"
"                    distortion.h \\\r\n"
"                    envelope.cpp \\\r\n"
"                    envelope.h \\\r\n"
"                    feedback.cpp \\\r\n"
"                    feedback.h \\\r\n"
"                    filter.cpp \\\r\n"
"                    filter.h \\\r\n"
"                    formant_manager.cpp \\\r\n"
"                    formant_manager.h \\\r\n"
"                    linear_slope.cpp \\\r\n"
"                    linear_slope.h \\\r\n"
"                    magnitude_lookup.cpp \\\r\n"
"                    magnitude_lookup.h \\\r\n"
"                    memory.cpp \\\r\n"
"                    memory.h \\\r\n"
"                    midi_lookup.cpp \\\r\n"
"                    midi_lookup.h \\\r\n"
"                    mono_panner.cpp \\\r\n"
"                    mono_panner.h \\\r\n"
"                    mopo.h \\\r\n"
"                    note_handler.h \\\r\n"
"                    operators.cpp \\\r\n"
"                    operators.h \\\r\n"
"                    oscillator.cpp \\\r\n"
"                    oscillator.h \\\r\n"
"                    phaser.cpp \\\r\n"
"                    phaser.h \\\r\n"
"                    portamento_slope.cpp \\\r\n"
"                    portamento_slope.h \\\r\n"
"                    processor.cpp \\\r\n"
"                    processor.h \\\r\n"
"                    processor_router.cpp \\\r\n"
"                    processor_router.h \\\r\n"
"                    resonance_lookup.cpp \\\r\n"
"                    resonance_lookup.h \\\r\n"
"\t\t\t\t\t\t\t\t\t\treverb.cpp \\\r\n"
"\t\t\t\t\t\t\t\t\t\treverb.h \\\r\n"
"\t\t\t\t\t\t\t\t\t\treverb_all_pass.cpp \\\r\n"
"\t\t\t\t\t\t\t\t\t\treverb_all_pass.h \\\r\n"
"\t\t\t\t\t\t\t\t\t\treverb_comb.cpp \\\r\n"
"\t\t\t\t\t\t\t\t\t\treverb_comb.h \\\r\n"
"                    simple_delay.cpp \\\r\n"
"                    simple_delay.h \\\r\n"
"                    smooth_filter.cpp \\\r\n"
"                    smooth_filter.h \\\r\n"
"                    smooth_value.cpp \\\r\n"
"                    smooth_value.h \\\r\n"
"                    step_generator.cpp \\\r\n"
"                    step_generator.h \\\r\n"
"                    stutter.cpp \\\r\n"
"                    stutter.h \\\r\n"
"                    tick_router.h \\\r\n"
"                    trigger_operators.cpp \\\r\n"
"                    trigger_operators.h \\\r\n"
"                    value.cpp \\\r\n"
"                    value.h \\\r\n"
"                    utils.h \\\r\n"
"                    voice_handler.cpp \\\r\n"
"                    voice_handler.h \\\r\n"
"                    wave.cpp \\\r\n"
"                    wave.h\r\n";

const char* Makefile_am = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x1a187401:  numBytes = 2686; return Makefile_am;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "Makefile_am"
};

const char* originalFilenames[] =
{
    "Makefile.am"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
