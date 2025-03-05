#ifndef MACRO_H
#define MACRO_H

#include <vector>
#include <string>

#define AddCommand(Module, Function) command.emplace(#Module "." #Function, Module::Function)
#define AddFunction(Module, Function) static std::string Function(std::vector<std::string> args)

#define AddCommands \
    AddCommand(Bias, Set); \
    AddCommand(Bias, Get); \
    AddCommand(Bias, RangeSet); \
    AddCommand(Bias, RangeGet); \
    AddCommand(Bias, CalibrSet); \
    AddCommand(Bias, CalibrGet); \
    AddCommand(Bias, Pulse); \
    AddCommand(BiasSwp, Open); \
    AddCommand(BiasSwp, Start); \
    AddCommand(BiasSwp, PropsSet); \
    AddCommand(BiasSwp, LimitsSet); \
    AddCommand(BiasSpectr, PropsGet); \
    AddCommand(BiasSpectr, AdvPropsSet); \
    AddCommand(BiasSpectr, AdvPropsGet); \
    AddCommand(BiasSpectr, LimitsSet); \
    AddCommand(BiasSpectr, LimitsGet); \
    AddCommand(BiasSpectr, TimingSet); \
    AddCommand(BiasSpectr, TimingGet); \
    AddCommand(BiasSpectr, TTLSyncSet); \
    AddCommand(BiasSpectr, TTLSyncGet); \
    AddCommand(BiasSpectr, AltZCtrlSet); \
    AddCommand(BiasSpectr, AltZCtrlGet); \
    AddCommand(BiasSpectr, MLSLockinPerSegSet); \
    AddCommand(BiasSpectr, MLSLockinPerSegGet); \
    AddCommand(BiasSpectr, MLSModeSet); \
    AddCommand(BiasSpectr, MLSModeGet); \
    AddCommand(BiasSpectr, MLSValsSet); \
    AddCommand(BiasSpectr, MLSValsGet); \
    AddCommand(KelvinCtrl, CtrlOnOffSet); \
    AddCommand(KelvinCtrl, CtrlOnOffGet); \
    AddCommand(KelvinCtrl, SetpntSet); \
    AddCommand(KelvinCtrl, SetpntGet); \
    AddCommand(KelvinCtrl, GainSet); \
    AddCommand(KelvinCtrl, GainGet);

#define AddBiasFunctions \
    AddFunction(Bias, Set); \
    AddFunction(Bias, Get); \
    AddFunction(Bias, RangeSet); \
    AddFunction(Bias, RangeGet); \
    AddFunction(Bias, CalibrSet); \
    AddFunction(Bias, CalibrGet); \
    AddFunction(Bias, Pulse); \

#define AddBiasSwpFunctions \
    AddFunction(BiasSwp, Open); \
    AddFunction(BiasSwp, Start); \
    AddFunction(BiasSwp, PropsSet); \
    AddFunction(BiasSwp, LimitsSet);

#define AddBiasSpectrFunctions \
    AddFunction(BiasSpectr, PropsGet); \
    AddFunction(BiasSpectr, AdvPropsSet); \
    AddFunction(BiasSpectr, AdvPropsGet); \
    AddFunction(BiasSpectr, LimitsSet); \
    AddFunction(BiasSpectr, LimitsGet); \
    AddFunction(BiasSpectr, TimingSet); \
    AddFunction(BiasSpectr, TimingGet); \
    AddFunction(BiasSpectr, TTLSyncSet); \
    AddFunction(BiasSpectr, TTLSyncGet); \
    AddFunction(BiasSpectr, AltZCtrlSet); \
    AddFunction(BiasSpectr, AltZCtrlGet); \
    AddFunction(BiasSpectr, MLSLockinPerSegSet); \
    AddFunction(BiasSpectr, MLSLockinPerSegGet); \
    AddFunction(BiasSpectr, MLSModeSet); \
    AddFunction(BiasSpectr, MLSModeGet); \
    AddFunction(BiasSpectr, MLSValsSet); \
    AddFunction(BiasSpectr, MLSValsGet);

#define AddKelvinCtrlFunctions \
    AddFunction(KelvinCtrl, CtrlOnOffSet); \
    AddFunction(KelvinCtrl, CtrlOnOffGet); \
    AddFunction(KelvinCtrl, SetpntSet); \
    AddFunction(KelvinCtrl, SetpntGet); \
    AddFunction(KelvinCtrl, GainSet); \
    AddFunction(KelvinCtrl, GainGet);

#endif // MACRO_H
