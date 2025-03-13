// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef MACRO_H
#define MACRO_H

#include <vector>
#include <string>

#define AddCommand(Module, Func) \
    m_command.emplace(#Module "." #Func, std::bind(&Function::Module##Func, &m_function, std::placeholders::_1));

#define AddFunction(Module, Func, ...) \
    inline void Module##Func(std::vector<std::string> &args) { \
        appendArgs<__VA_ARGS__ __VA_OPT__(,) void>(m_os, args); \
    }

#define AddDumpFunction(Module, Func, ...) \
    inline void Dump##Module##Func(const std::string &dumpBody, size_t *offset) { \
        appendDumps<__VA_ARGS__ __VA_OPT__(,) void>(m_os, dumpBody, offset); \
    }

#define AddTclCommand(Module, Func) \
    inline int Module##Func(Tcl_Interp *interp, int objc, Tcl_Obj *const *objv) { \
        std::string commandName = Tcl_GetStringFromObj(objv[0], NULL); \
        std::vector<std::string> args; \
        for (int i = 1; i < objc; i++) \
            args.emplace_back(Tcl_GetStringFromObj(objv[i], NULL)); \
        m_command.invoke(commandName, args); \
        return TCL_OK; \
    }

#define RegisterTclCommand(Module, Func) \
    Tcl_CreateObjCommand(m_interp, #Module "." #Func, CallbackWrapper(Module##Func), this, NULL);

#define AddDumpCommand(Module, Func) \
    m_dumpCommand.emplace(#Module "." #Func, std::bind(&Function::Dump##Module##Func, &m_function, std::placeholders::_1, std::placeholders::_2));

#define AddDumpCommands \
    AddDumpCommand(Bias, Set); \
    AddDumpCommand(Bias, Get); \
    AddDumpCommand(Bias, RangeSet); \
    AddDumpCommand(Bias, RangeGet); \
    AddDumpCommand(Bias, CalibrSet); \
    AddDumpCommand(Bias, CalibrGet); \
    AddDumpCommand(Bias, Pulse); \
    AddDumpCommand(BiasSwp, Open); \
    AddDumpCommand(BiasSwp, Start); \
    AddDumpCommand(BiasSwp, PropsSet); \
    AddDumpCommand(BiasSwp, LimitsSet); \
    AddDumpCommand(BiasSpectr, PropsGet); \
    AddDumpCommand(BiasSpectr, AdvPropsSet); \
    AddDumpCommand(BiasSpectr, AdvPropsGet); \
    AddDumpCommand(BiasSpectr, LimitsSet); \
    AddDumpCommand(BiasSpectr, LimitsGet); \
    AddDumpCommand(BiasSpectr, TimingSet); \
    AddDumpCommand(BiasSpectr, TimingGet); \
    AddDumpCommand(BiasSpectr, TTLSyncSet); \
    AddDumpCommand(BiasSpectr, TTLSyncGet); \
    AddDumpCommand(BiasSpectr, AltZCtrlSet); \
    AddDumpCommand(BiasSpectr, AltZCtrlGet); \
    AddDumpCommand(BiasSpectr, MLSLockinPerSegSet); \
    AddDumpCommand(BiasSpectr, MLSLockinPerSegGet); \
    AddDumpCommand(BiasSpectr, MLSModeSet); \
    AddDumpCommand(BiasSpectr, MLSModeGet); \
    AddDumpCommand(BiasSpectr, MLSValsSet); \
    AddDumpCommand(BiasSpectr, MLSValsGet); \
    AddDumpCommand(KelvinCtrl, CtrlOnOffSet); \
    AddDumpCommand(KelvinCtrl, CtrlOnOffGet); \
    AddDumpCommand(KelvinCtrl, SetpntSet); \
    AddDumpCommand(KelvinCtrl, SetpntGet); \
    AddDumpCommand(KelvinCtrl, GainSet); \
    AddDumpCommand(KelvinCtrl, GainGet); \
    AddDumpCommand(KelvinCtrl, ModParamsSet); \
    AddDumpCommand(KelvinCtrl, ModParamsGet); \
    AddDumpCommand(KelvinCtrl, ModOnOffSet); \
    AddDumpCommand(KelvinCtrl, ModOnOffGet); \
    AddDumpCommand(KelvinCtrl, CtrlSignalSet); \
    AddDumpCommand(KelvinCtrl, CtrlSignalGet); \
    AddDumpCommand(KelvinCtrl, AmpGet); \
    AddDumpCommand(KelvinCtrl, BiasLimitsSet); \
    AddDumpCommand(KelvinCtrl, BiasLimitsGet); \
    AddDumpCommand(CPDComp, Open); \
    AddDumpCommand(CPDComp, Close); \
    AddDumpCommand(CPDComp, ParamsSet); \
    AddDumpCommand(CPDComp, ParamsGet); \
    AddDumpCommand(CPDComp, DataGet); \
    AddDumpCommand(Current, Get); \
    AddDumpCommand(Current, Get100); \
    AddDumpCommand(Current, BEEMGet); \
    AddDumpCommand(Current, GainSet); \
    AddDumpCommand(Current, GainsGet); \
    AddDumpCommand(Current, CalibrSet); \
    AddDumpCommand(Current, CalibrGet); \
    AddDumpCommand(ZCtrl, ZPosSet); \
    AddDumpCommand(ZCtrl, ZPosGet); \
    AddDumpCommand(ZCtrl, OnOffSet); \
    AddDumpCommand(ZCtrl, OnOffGet); \
    AddDumpCommand(ZCtrl, SetpntSet); \
    AddDumpCommand(ZCtrl, SetpntGet); \
    AddDumpCommand(ZCtrl, GainSet); \
    AddDumpCommand(ZCtrl, GainGet); \
    AddDumpCommand(ZCtrl, SwitchOffDelaySet); \
    AddDumpCommand(ZCtrl, SwitchOffDelayGet); \
    AddDumpCommand(ZCtrl, TipLiftSet); \
    AddDumpCommand(ZCtrl, TipLiftGet); \
    AddDumpCommand(ZCtrl, Home); \
    AddDumpCommand(ZCtrl, HomePropsSet); \
    AddDumpCommand(ZCtrl, HomePropsGet); \
    AddDumpCommand(ZCtrl, ActiveCtrlSet); \
    AddDumpCommand(ZCtrl, CtrlListGet); \
    AddDumpCommand(ZCtrl, Withdraw); \
    AddDumpCommand(ZCtrl, WithdrawRateSet); \
    AddDumpCommand(ZCtrl, WithdrawRateGet); \
    AddDumpCommand(ZCtrl, LimitsEnabledSet); \
    AddDumpCommand(ZCtrl, LimitsEnabledGet); \
    AddDumpCommand(ZCtrl, LimitsSet); \
    AddDumpCommand(ZCtrl, LimitsGet); \
    AddDumpCommand(ZCtrl, StatusGet); \
    AddDumpCommand(SafeTip, OnOffSet); \
    AddDumpCommand(SafeTip, OnOffGet); \
    AddDumpCommand(SafeTip, SignalGet); \
    AddDumpCommand(SafeTip, PropsSet); \
    AddDumpCommand(SafeTip, PropsGet); \
    AddDumpCommand(AutoApproach, Open); \
    AddDumpCommand(AutoApproach, OnOffSet); \
    AddDumpCommand(AutoApproach, OnOffGet); \
    AddDumpCommand(ZSpectr, Open); \
    AddDumpCommand(ZSpectr, Start); \
    AddDumpCommand(ZSpectr, Stop); \
    AddDumpCommand(ZSpectr, StatusGet); \
    AddDumpCommand(ZSpectr, ChsSet); \
    AddDumpCommand(ZSpectr, ChsGet); \
    AddDumpCommand(ZSpectr, PropsSet); \
    AddDumpCommand(ZSpectr, PropsGet); \
    AddDumpCommand(ZSpectr, AdvPropsSet); \
    AddDumpCommand(ZSpectr, AdvPropsGet); \
    AddDumpCommand(ZSpectr, RangeSet); \
    AddDumpCommand(ZSpectr, RangeGet); \
    AddDumpCommand(ZSpectr, TimingSet); \
    AddDumpCommand(ZSpectr, TimingGet); \
    AddDumpCommand(ZSpectr, RetractDelaySet); \
    AddDumpCommand(ZSpectr, RetractDelayGet); \
    AddDumpCommand(ZSpectr, RetractSet); \
    AddDumpCommand(ZSpectr, RetractGet); \
    AddDumpCommand(ZSpectr, Retract2ndSet); \
    AddDumpCommand(ZSpectr, Retract2ndGet); \
    AddDumpCommand(Piezo, TiltSet); \
    AddDumpCommand(Piezo, TiltGet); \
    AddDumpCommand(Piezo, RangeSet); \
    AddDumpCommand(Piezo, RangeGet); \
    AddDumpCommand(Piezo, SensSet); \
    AddDumpCommand(Piezo, SensGet); \
    AddDumpCommand(Piezo, DriftCompSet); \
    AddDumpCommand(Piezo, DriftCompGet); \
    AddDumpCommand(Piezo, CalibrGet); \
    AddDumpCommand(Piezo, HVAInfoGet); \
    AddDumpCommand(Piezo, HVAStatusLEDGet); \
    AddDumpCommand(Scan, Action); \
    AddDumpCommand(Scan, StatusGet); \
    AddDumpCommand(Scan, WaitEndOfScan); \
    AddDumpCommand(Scan, FrameSet); \
    AddDumpCommand(Scan, FrameGet); \
    AddDumpCommand(Scan, BufferSet); \
    AddDumpCommand(Scan, BufferGet); \
    AddDumpCommand(Scan, PropsSet); \
    AddDumpCommand(Scan, PropsGet); \
    AddDumpCommand(Scan, SpeedSet); \
    AddDumpCommand(Scan, SpeedGet); \
    AddDumpCommand(Scan, FrameDataGrab); \
    AddDumpCommand(FolMe, XYPosSet); \
    AddDumpCommand(FolMe, XYPosGet); \
    AddDumpCommand(FolMe, SpeedSet); \
    AddDumpCommand(FolMe, SpeedGet); \
    AddDumpCommand(FolMe, OversamplSet); \
    AddDumpCommand(FolMe, OversamplGet); \
    AddDumpCommand(FolMe, Stop); \
    AddDumpCommand(FolMe, PSOnOffGet); \
    AddDumpCommand(FolMe, PSOnOffSet); \
    AddDumpCommand(FolMe, PSExpGet); \
    AddDumpCommand(FolMe, PSExpSet); \
    AddDumpCommand(FolMe, PSPropsGet); \
    AddDumpCommand(FolMe, PSPropsSet); \
    AddDumpCommand(TipRec, BufferSizeSet); \
    AddDumpCommand(TipRec, BufferSizeGet); \
    AddDumpCommand(TipRec, BufferClear); \
    AddDumpCommand(TipRec, DataGet); \
    AddDumpCommand(TipRec, DataSave); \
    AddDumpCommand(Pattern, ExpOpen); \
    AddDumpCommand(Pattern, ExpStart); \
    AddDumpCommand(Pattern, ExpPause); \
    AddDumpCommand(Pattern, ExpStop); \
    AddDumpCommand(Pattern, ExpStatusGet); \
    AddDumpCommand(Pattern, GridSet); \
    AddDumpCommand(Pattern, GridGet); \
    AddDumpCommand(Pattern, LineSet); \
    AddDumpCommand(Pattern, LineGet); \
    AddDumpCommand(Pattern, CloudSet); \
    AddDumpCommand(Pattern, CloudGet); \
    AddDumpCommand(Pattern, PropsSet); \
    AddDumpCommand(Pattern, PropsGet); \
    AddDumpCommand(Marks, PointDraw); \
    AddDumpCommand(Marks, PointsDraw); \
    AddDumpCommand(Marks, LineDraw); \
    AddDumpCommand(Marks, LinesDraw); \
    AddDumpCommand(Marks, PointsErase); \
    AddDumpCommand(Marks, LinesErase); \
    AddDumpCommand(Marks, PointsVisibleSet); \
    AddDumpCommand(Marks, LinesVisibleSet); \
    AddDumpCommand(Marks, PointsGet); \
    AddDumpCommand(Marks, LinesGet); \
    AddDumpCommand(TipShaper, Start); \
    AddDumpCommand(TipShaper, PropsSet); \
    AddDumpCommand(TipShaper, PropsGet); \
    AddDumpCommand(Motor, StartMove); \
    AddDumpCommand(Motor, StartClosedLoop); \
    AddDumpCommand(Motor, StopMove); \
    AddDumpCommand(Motor, PosGet); \
    AddDumpCommand(Motor, StepCounterGet); \
    AddDumpCommand(Motor, FreqAmpGet); \
    AddDumpCommand(Motor, FreqAmpSet); \
    AddDumpCommand(GenSwp, AcqChsSet); \
    AddDumpCommand(GenSwp, AcqChsGet); \
    AddDumpCommand(GenSwp, SwpSignalSet); \
    AddDumpCommand(GenSwp, SwpSignalGet); \
    AddDumpCommand(GenSwp, LimitsSet); \
    AddDumpCommand(GenSwp, LimitsGet); \
    AddDumpCommand(GenSwp, PropsSet); \
    AddDumpCommand(GenSwp, PropsGet); \
    AddDumpCommand(GenSwp, Start); \
    AddDumpCommand(GenSwp, Stop); \
    AddDumpCommand(GenSwp, Open); \
    AddDumpCommand(GenPICtrl, OnOffSet); \
    AddDumpCommand(GenPICtrl, OnOffGet); \
    AddDumpCommand(GenPICtrl, AOValSet); \
    AddDumpCommand(GenPICtrl, AOValGet); \
    AddDumpCommand(GenPICtrl, AOPropsSet); \
    AddDumpCommand(GenPICtrl, AOPropsGet); \
    AddDumpCommand(GenPICtrl, ModChSet); \
    AddDumpCommand(GenPICtrl, ModChGet); \
    AddDumpCommand(GenPICtrl, DemodChSet); \
    AddDumpCommand(GenPICtrl, DemodChGet); \
    AddDumpCommand(GenPICtrl, PropsSet); \
    AddDumpCommand(GenPICtrl, PropsGet); \
    AddDumpCommand(AtomTrack, CtrlSet); \
    AddDumpCommand(AtomTrack, StatusGet); \
    AddDumpCommand(AtomTrack, PropsSet); \
    AddDumpCommand(AtomTrack, PropsGet); \
    AddDumpCommand(AtomTrack, QuickCompStart); \
    AddDumpCommand(AtomTrack, DriftComp); \
    AddDumpCommand(LockIn, ModOnOffSet); \
    AddDumpCommand(LockIn, ModOnOffGet); \
    AddDumpCommand(LockIn, ModSignalSet); \
    AddDumpCommand(LockIn, ModSignalGet); \
    AddDumpCommand(LockIn, ModPhasRegSet); \
    AddDumpCommand(LockIn, ModPhasRegGet); \
    AddDumpCommand(LockIn, ModHarmonicSet); \
    AddDumpCommand(LockIn, ModHarmonicGet); \
    AddDumpCommand(LockIn, ModPhasSet); \
    AddDumpCommand(LockIn, ModPhasGet); \
    AddDumpCommand(LockIn, ModAmpSet); \
    AddDumpCommand(LockIn, ModAmpGet); \
    AddDumpCommand(LockIn, ModPhasFreqSet); \
    AddDumpCommand(LockIn, ModPhasFreqGet); \
    AddDumpCommand(LockIn, DemodSignalSet); \
    AddDumpCommand(LockIn, DemodSignalGet); \
    AddDumpCommand(LockIn, DemodHarmonicSet); \
    AddDumpCommand(LockIn, DemodHarmonicGet); \
    AddDumpCommand(LockIn, DemodHPFilterSet); \
    AddDumpCommand(LockIn, DemodHPFilterGet); \
    AddDumpCommand(LockIn, DemodLPFilterSet); \
    AddDumpCommand(LockIn, DemodLPFilterGet); \
    AddDumpCommand(LockIn, DemodPhasRegSet); \
    AddDumpCommand(LockIn, DemodPhasRegGet); \
    AddDumpCommand(LockIn, DemodPhasSet); \
    AddDumpCommand(LockIn, DemodPhasGet); \
    AddDumpCommand(LockIn, DemodSyncFilterSet); \
    AddDumpCommand(LockIn, DemodSyncFilterGet); \
    AddDumpCommand(LockIn, DemodRTSignalsSet); \
    AddDumpCommand(LockIn, DemodRTSignalsGet); \
    AddDumpCommand(LockInFreqSwp, Open); \
    AddDumpCommand(LockInFreqSwp, Start); \
    AddDumpCommand(LockInFreqSwp, SignalSet); \
    AddDumpCommand(LockInFreqSwp, SignalGet); \
    AddDumpCommand(LockInFreqSwp, LimitsSet); \
    AddDumpCommand(LockInFreqSwp, LimitsGet); \
    AddDumpCommand(LockInFreqSwp, PropsSet); \
    AddDumpCommand(LockInFreqSwp, PropsGet); \
    AddDumpCommand(PLL, InpCalibrSet); \
    AddDumpCommand(PLL, InpCalibrGet); \
    AddDumpCommand(PLL, InpRangeSet); \
    AddDumpCommand(PLL, InpRangeGet); \
    AddDumpCommand(PLL, InpPropsSet); \
    AddDumpCommand(PLL, InpPropsGet); \
    AddDumpCommand(PLL, AddOnOffSet); \
    AddDumpCommand(PLL, AddOnOffGet); \
    AddDumpCommand(PLL, OutOnOffSet); \
    AddDumpCommand(PLL, OutOnOffGet); \
    AddDumpCommand(PLL, ExcRangeSet); \
    AddDumpCommand(PLL, ExcRangeGet); \
    AddDumpCommand(PLL, ExcitationSet); \
    AddDumpCommand(PLL, ExcitationGet); \
    AddDumpCommand(PLL, AmpCtrlSetpntSet); \
    AddDumpCommand(PLL, AmpCtrlSetpntGet); \
    AddDumpCommand(PLL, AmpCtrlOnOffSet); \
    AddDumpCommand(PLL, AmpCtrlOnOffGet); \
    AddDumpCommand(PLL, AmpCtrlGainSet); \
    AddDumpCommand(PLL, AmpCtrlGainGet); \
    AddDumpCommand(PLL, AmpCtrlBandwidthSet); \
    AddDumpCommand(PLL, AmpCtrlBandwidthGet); \
    AddDumpCommand(PLL, PhasCtrlOnOffSet); \
    AddDumpCommand(PLL, PhasCtrlOnOffGet); \
    AddDumpCommand(PLL, PhasCtrlGainSet); \
    AddDumpCommand(PLL, PhasCtrlGainGet); \
    AddDumpCommand(PLL, PhasCtrlBandwidthSet); \
    AddDumpCommand(PLL, PhasCtrlBandwidthGet); \
    AddDumpCommand(PLL, FreqRangeSet); \
    AddDumpCommand(PLL, FreqRangeGet); \
    AddDumpCommand(PLL, CenterFreqSet); \
    AddDumpCommand(PLL, CenterFreqGet); \
    AddDumpCommand(PLL, FreqShiftSet); \
    AddDumpCommand(PLL, FreqShiftGet); \
    AddDumpCommand(PLL, FreqShiftAutoCenter); \
    AddDumpCommand(PLL, FreqExcOverwriteSet); \
    AddDumpCommand(PLL, FreqExcOverwriteGet); \
    AddDumpCommand(PLL, DemodInputSet); \
    AddDumpCommand(PLL, DemodInputGet); \
    AddDumpCommand(PLL, DemodHarmonicSet); \
    AddDumpCommand(PLL, DemodHarmonicGet); \
    AddDumpCommand(PLL, DemodPhasRefSet); \
    AddDumpCommand(PLL, DemodPhasRefGet); \
    AddDumpCommand(PLL, DemodFilterSet); \
    AddDumpCommand(PLL, DemodFilterGet); \
    AddDumpCommand(PLLQCtrl, AccessRequest); \
    AddDumpCommand(PLLQCtrl, AccessGet); \
    AddDumpCommand(PLLQCtrl, OnOffSet); \
    AddDumpCommand(PLLQCtrl, OnOffGet); \
    AddDumpCommand(PLLQCtrl, QGainSet); \
    AddDumpCommand(PLLQCtrl, QGainGet); \
    AddDumpCommand(PLLQCtrl, PhaseSet); \
    AddDumpCommand(PLLQCtrl, PhaseGet); \
    AddDumpCommand(PLLFreqSwp, Open); \
    AddDumpCommand(PLLFreqSwp, ParamsSet); \
    AddDumpCommand(PLLFreqSwp, ParamsGet); \
    AddDumpCommand(PLLFreqSwp, Start); \
    AddDumpCommand(PLLFreqSwp, Stop); \
    AddDumpCommand(PLLPhasSwp, Start); \
    AddDumpCommand(PLLPhasSwp, Stop); \
    AddDumpCommand(PLLSignalAnlzr, Open); \
    AddDumpCommand(PLLSignalAnlzr, ChSet); \
    AddDumpCommand(PLLSignalAnlzr, ChGet); \
    AddDumpCommand(PLLSignalAnlzr, TimebaseSet); \
    AddDumpCommand(PLLSignalAnlzr, TimebaseGet); \
    AddDumpCommand(PLLSignalAnlzr, TrigAuto); \
    AddDumpCommand(PLLSignalAnlzr, TrigRearm); \
    AddDumpCommand(PLLSignalAnlzr, TrigSet); \
    AddDumpCommand(PLLSignalAnlzr, TrigGet); \
    AddDumpCommand(PLLSignalAnlzr, OsciDataGet); \
    AddDumpCommand(PLLSignalAnlzr, FFTPropsSet); \
    AddDumpCommand(PLLSignalAnlzr, FFTPropsGet); \
    AddDumpCommand(PLLSignalAnlzr, FFTAvgRestart); \
    AddDumpCommand(PLLSignalAnlzr, FFTDataGet); \
    AddDumpCommand(PLLZoomFFT, Open); \
    AddDumpCommand(PLLZoomFFT, ChSet); \
    AddDumpCommand(PLLZoomFFT, ChGet); \
    AddDumpCommand(PLLZoomFFT, AvgRestart); \
    AddDumpCommand(PLLZoomFFT, PropsSet); \
    AddDumpCommand(PLLZoomFFT, PropsGet); \
    AddDumpCommand(PLLZoomFFT, DataGet); \
    AddDumpCommand(OCSync, AnglesSet); \
    AddDumpCommand(OCSync, AnglesGet); \
    AddDumpCommand(OCSync, LinkAnglesSet); \
    AddDumpCommand(OCSync, LinkAnglesGet); \
    AddDumpCommand(Script, Load); \
    AddDumpCommand(Script, Save); \
    AddDumpCommand(Script, Deploy); \
    AddDumpCommand(Script, Undeploy); \
    AddDumpCommand(Script, Run); \
    AddDumpCommand(Script, Stop); \
    AddDumpCommand(Script, ChsGet); \
    AddDumpCommand(Script, ChsSet); \
    AddDumpCommand(Script, DataGet); \
    AddDumpCommand(Script, Autosave); \
    AddDumpCommand(Interf, CtrlOnOffSet); \
    AddDumpCommand(Interf, CtrlOnOffGet); \
    AddDumpCommand(Interf, CtrlPropsSet); \
    AddDumpCommand(Interf, CtrlPropsGet); \
    AddDumpCommand(Interf, WPiezoSet); \
    AddDumpCommand(Interf, WPiezoGet); \
    AddDumpCommand(Interf, ValGet); \
    AddDumpCommand(Interf, CtrlCalibrOpen); \
    AddDumpCommand(Interf, CtrlReset); \
    AddDumpCommand(Interf, CtrlNullDefl); \
    AddDumpCommand(Laser, OnOffSet); \
    AddDumpCommand(Laser, OnOffGet); \
    AddDumpCommand(Laser, PropsSet); \
    AddDumpCommand(Laser, PropsGet); \
    AddDumpCommand(Laser, PowerGet); \
    AddDumpCommand(BeamDefl, HorConfigSet); \
    AddDumpCommand(BeamDefl, HorConfigGet); \
    AddDumpCommand(BeamDefl, VerConfigSet); \
    AddDumpCommand(BeamDefl, VerConfigGet); \
    AddDumpCommand(BeamDefl, IntConfigSet); \
    AddDumpCommand(BeamDefl, IntConfigGet); \
    AddDumpCommand(BeamDefl, AutoOffset); \
    AddDumpCommand(Signals, NamesGet); \
    AddDumpCommand(Signals, InSlotSet); \
    AddDumpCommand(Signals, InSlotsGet); \
    AddDumpCommand(Signals, CalibrGet); \
    AddDumpCommand(Signals, RangeGet); \
    AddDumpCommand(Signals, ValGet); \
    AddDumpCommand(Signals, ValsGet); \
    AddDumpCommand(Signals, MeasNamesGet); \
    AddDumpCommand(Signals, AddRTGet); \
    AddDumpCommand(Signals, AddRTSet); \
    AddDumpCommand(UserIn, CalibrSet); \
    AddDumpCommand(UserOut, ModeSet); \
    AddDumpCommand(UserOut, ModeGet); \
    AddDumpCommand(UserOut, MonitorChSet); \
    AddDumpCommand(UserOut, MonitorChGet); \
    AddDumpCommand(UserOut, ValSet); \
    AddDumpCommand(UserOut, CalibrSet); \
    AddDumpCommand(UserOut, CalcSignalNameSet); \
    AddDumpCommand(UserOut, CalcSignalNameGet); \
    AddDumpCommand(UserOut, CalcSignalConfigSet); \
    AddDumpCommand(UserOut, CalcSignalConfigGet); \
    AddDumpCommand(UserOut, LimitsSet); \
    AddDumpCommand(UserOut, LimitsGet); \
    AddDumpCommand(DigLines, PropsSet); \
    AddDumpCommand(DigLines, OutStatusSet); \
    AddDumpCommand(DigLines, TTLValGet); \
    AddDumpCommand(DigLines, Pulse); \
    AddDumpCommand(DataLog, Open); \
    AddDumpCommand(DataLog, Start); \
    AddDumpCommand(DataLog, Stop); \
    AddDumpCommand(DataLog, StatusGet); \
    AddDumpCommand(DataLog, ChsSet); \
    AddDumpCommand(DataLog, ChsGet); \
    AddDumpCommand(DataLog, PropsSet); \
    AddDumpCommand(DataLog, PropsGet); \
    AddDumpCommand(TCPLog, Start); \
    AddDumpCommand(TCPLog, Stop); \
    AddDumpCommand(TCPLog, ChsSet); \
    AddDumpCommand(TCPLog, OversamplSet); \
    AddDumpCommand(TCPLog, StatusGet); \
    AddDumpCommand(OsciHR, ChSet); \
    AddDumpCommand(OsciHR, ChGet); \
    AddDumpCommand(OsciHR, OversamplSet); \
    AddDumpCommand(OsciHR, OversamplGet); \
    AddDumpCommand(OsciHR, CalibrModeSet); \
    AddDumpCommand(OsciHR, CalibrModeGet); \
    AddDumpCommand(OsciHR, SamplesSet); \
    AddDumpCommand(OsciHR, SamplesGet); \
    AddDumpCommand(OsciHR, PreTrigSet); \
    AddDumpCommand(OsciHR, PreTrigGet); \
    AddDumpCommand(OsciHR, Run); \
    AddDumpCommand(OsciHR, OsciDataGet); \
    AddDumpCommand(OsciHR, TrigModeSet); \
    AddDumpCommand(OsciHR, TrigModeGet); \
    AddDumpCommand(OsciHR, TrigLevChSet); \
    AddDumpCommand(OsciHR, TrigLevChGet); \
    AddDumpCommand(OsciHR, TrigLevValSet); \
    AddDumpCommand(OsciHR, TrigLevValGet); \
    AddDumpCommand(OsciHR, TrigLevHystSet); \
    AddDumpCommand(OsciHR, TrigLevHystGet); \
    AddDumpCommand(OsciHR, TrigLevSlopeSet); \
    AddDumpCommand(OsciHR, TrigLevSlopeGet); \
    AddDumpCommand(OsciHR, TrigDigChSet); \
    AddDumpCommand(OsciHR, TrigDigChGet); \
    AddDumpCommand(OsciHR, TrigArmModeSet); \
    AddDumpCommand(OsciHR, TrigArmModeGet); \
    AddDumpCommand(OsciHR, TrigDigSlopeSet); \
    AddDumpCommand(OsciHR, TrigDigSlopeGet); \
    AddDumpCommand(OsciHR, TrigRearm); \
    AddDumpCommand(OsciHR, PSDShow); \
    AddDumpCommand(OsciHR, PSDWeightSet); \
    AddDumpCommand(OsciHR, PSDWeightGet); \
    AddDumpCommand(OsciHR, PSDWindowSet); \
    AddDumpCommand(OsciHR, PSDWindowGet); \
    AddDumpCommand(OsciHR, PSDAvrgTypeSet); \
    AddDumpCommand(OsciHR, PSDAvrgTypeGet); \
    AddDumpCommand(OsciHR, PSDAvrgCountSet); \
    AddDumpCommand(OsciHR, PSDAvrgCountGet); \
    AddDumpCommand(OsciHR, PSDAvrgRestart); \
    AddDumpCommand(OsciHR, PSDDataGet); \
    AddDumpCommand(Osci1T, ChSet); \
    AddDumpCommand(Osci1T, ChGet); \
    AddDumpCommand(Osci1T, TimebaseSet); \
    AddDumpCommand(Osci1T, TimebaseGet); \
    AddDumpCommand(Osci1T, TrigSet); \
    AddDumpCommand(Osci1T, TrigGet); \
    AddDumpCommand(Osci1T, Run); \
    AddDumpCommand(Osci1T, DataGet); \
    AddDumpCommand(Osci2T, ChsSet); \
    AddDumpCommand(Osci2T, ChsGet); \
    AddDumpCommand(Osci2T, TimebaseSet); \
    AddDumpCommand(Osci2T, TimebaseGet); \
    AddDumpCommand(Osci2T, OversamplSet); \
    AddDumpCommand(Osci2T, OversamplGet); \
    AddDumpCommand(Osci2T, TrigSet); \
    AddDumpCommand(Osci2T, TrigGet); \
    AddDumpCommand(Osci2T, Run); \
    AddDumpCommand(Osci2T, DataGet); \
    AddDumpCommand(SignalChart, Open); \
    AddDumpCommand(SignalChart, ChsSet); \
    AddDumpCommand(SignalChart, ChsGet); \
    AddDumpCommand(SpectrumAnlzr, ChSet); \
    AddDumpCommand(SpectrumAnlzr, ChGet); \
    AddDumpCommand(SpectrumAnlzr, FreqRangeSet); \
    AddDumpCommand(SpectrumAnlzr, FreqRangeGet); \
    AddDumpCommand(SpectrumAnlzr, FreqResSet); \
    AddDumpCommand(SpectrumAnlzr, FreqResGet); \
    AddDumpCommand(SpectrumAnlzr, FFTWindowSet); \
    AddDumpCommand(SpectrumAnlzr, FFTWindowGet); \
    AddDumpCommand(SpectrumAnlzr, AveragSet); \
    AddDumpCommand(SpectrumAnlzr, AveragGet); \
    AddDumpCommand(SpectrumAnlzr, ACCouplingSet); \
    AddDumpCommand(SpectrumAnlzr, ACCouplingGet); \
    AddDumpCommand(SpectrumAnlzr, CursorPosSet); \
    AddDumpCommand(SpectrumAnlzr, CursorPosGet); \
    AddDumpCommand(SpectrumAnlzr, BandRMSGet); \
    AddDumpCommand(SpectrumAnlzr, DCGet); \
    AddDumpCommand(SpectrumAnlzr, Run); \
    AddDumpCommand(SpectrumAnlzr, DataGet); \
    AddDumpCommand(FunGen1Ch, Start); \
    AddDumpCommand(FunGen1Ch, Stop); \
    AddDumpCommand(FunGen1Ch, StatusGet); \
    AddDumpCommand(FunGen1Ch, PropsSet); \
    AddDumpCommand(FunGen1Ch, PropsGet); \
    AddDumpCommand(FunGen1Ch, IdleSet); \
    AddDumpCommand(FunGen1Ch, IdleGet); \
    AddDumpCommand(FunGen2Ch, Start); \
    AddDumpCommand(FunGen2Ch, Stop); \
    AddDumpCommand(FunGen2Ch, StatusGet); \
    AddDumpCommand(FunGen2Ch, IdleSet); \
    AddDumpCommand(FunGen2Ch, IdleGet); \
    AddDumpCommand(FunGen2Ch, OnOffSet); \
    AddDumpCommand(FunGen2Ch, OnOffGet); \
    AddDumpCommand(FunGen2Ch, SignalSet); \
    AddDumpCommand(FunGen2Ch, SignalGet); \
    AddDumpCommand(FunGen2Ch, PropsSet); \
    AddDumpCommand(FunGen2Ch, PropsGet); \
    AddDumpCommand(FunGen2Ch, WaveformSet); \
    AddDumpCommand(FunGen2Ch, WaveformGet); \
    AddDumpCommand(Util, SessionPathGet); \
    AddDumpCommand(Util, SettingsLoad); \
    AddDumpCommand(Util, SettingsSave); \
    AddDumpCommand(Util, LayoutLoad); \
    AddDumpCommand(Util, LayoutSave); \
    AddDumpCommand(Util, Lock); \
    AddDumpCommand(Util, UnLock); \
    AddDumpCommand(Util, RTFreqSet); \
    AddDumpCommand(Util, RTFreqGet); \
    AddDumpCommand(Util, AcqPeriodSet); \
    AddDumpCommand(Util, AcqPeriodGet); \
    AddDumpCommand(Util, RTOversamplSet); \
    AddDumpCommand(Util, RTOversamplGet); \
    AddDumpCommand(Util, Quit);

#define AddTclCommands \
    AddTclCommand(Bias, Set); \
    AddTclCommand(Bias, Get); \
    AddTclCommand(Bias, RangeSet); \
    AddTclCommand(Bias, RangeGet); \
    AddTclCommand(Bias, CalibrSet); \
    AddTclCommand(Bias, CalibrGet); \
    AddTclCommand(Bias, Pulse); \
    AddTclCommand(BiasSwp, Open); \
    AddTclCommand(BiasSwp, Start); \
    AddTclCommand(BiasSwp, PropsSet); \
    AddTclCommand(BiasSwp, LimitsSet); \
    AddTclCommand(BiasSpectr, PropsGet); \
    AddTclCommand(BiasSpectr, AdvPropsSet); \
    AddTclCommand(BiasSpectr, AdvPropsGet); \
    AddTclCommand(BiasSpectr, LimitsSet); \
    AddTclCommand(BiasSpectr, LimitsGet); \
    AddTclCommand(BiasSpectr, TimingSet); \
    AddTclCommand(BiasSpectr, TimingGet); \
    AddTclCommand(BiasSpectr, TTLSyncSet); \
    AddTclCommand(BiasSpectr, TTLSyncGet); \
    AddTclCommand(BiasSpectr, AltZCtrlSet); \
    AddTclCommand(BiasSpectr, AltZCtrlGet); \
    AddTclCommand(BiasSpectr, MLSLockinPerSegSet); \
    AddTclCommand(BiasSpectr, MLSLockinPerSegGet); \
    AddTclCommand(BiasSpectr, MLSModeSet); \
    AddTclCommand(BiasSpectr, MLSModeGet); \
    AddTclCommand(BiasSpectr, MLSValsSet); \
    AddTclCommand(BiasSpectr, MLSValsGet); \
    AddTclCommand(KelvinCtrl, CtrlOnOffSet); \
    AddTclCommand(KelvinCtrl, CtrlOnOffGet); \
    AddTclCommand(KelvinCtrl, SetpntSet); \
    AddTclCommand(KelvinCtrl, SetpntGet); \
    AddTclCommand(KelvinCtrl, GainSet); \
    AddTclCommand(KelvinCtrl, GainGet); \
    AddTclCommand(KelvinCtrl, ModParamsSet); \
    AddTclCommand(KelvinCtrl, ModParamsGet); \
    AddTclCommand(KelvinCtrl, ModOnOffSet); \
    AddTclCommand(KelvinCtrl, ModOnOffGet); \
    AddTclCommand(KelvinCtrl, CtrlSignalSet); \
    AddTclCommand(KelvinCtrl, CtrlSignalGet); \
    AddTclCommand(KelvinCtrl, AmpGet); \
    AddTclCommand(KelvinCtrl, BiasLimitsSet); \
    AddTclCommand(KelvinCtrl, BiasLimitsGet); \
    AddTclCommand(CPDComp, Open); \
    AddTclCommand(CPDComp, Close); \
    AddTclCommand(CPDComp, ParamsSet); \
    AddTclCommand(CPDComp, ParamsGet); \
    AddTclCommand(CPDComp, DataGet); \
    AddTclCommand(Current, Get); \
    AddTclCommand(Current, Get100); \
    AddTclCommand(Current, BEEMGet); \
    AddTclCommand(Current, GainSet); \
    AddTclCommand(Current, GainsGet); \
    AddTclCommand(Current, CalibrSet); \
    AddTclCommand(Current, CalibrGet); \
    AddTclCommand(ZCtrl, ZPosSet); \
    AddTclCommand(ZCtrl, ZPosGet); \
    AddTclCommand(ZCtrl, OnOffSet); \
    AddTclCommand(ZCtrl, OnOffGet); \
    AddTclCommand(ZCtrl, SetpntSet); \
    AddTclCommand(ZCtrl, SetpntGet); \
    AddTclCommand(ZCtrl, GainSet); \
    AddTclCommand(ZCtrl, GainGet); \
    AddTclCommand(ZCtrl, SwitchOffDelaySet); \
    AddTclCommand(ZCtrl, SwitchOffDelayGet); \
    AddTclCommand(ZCtrl, TipLiftSet); \
    AddTclCommand(ZCtrl, TipLiftGet); \
    AddTclCommand(ZCtrl, Home); \
    AddTclCommand(ZCtrl, HomePropsSet); \
    AddTclCommand(ZCtrl, HomePropsGet); \
    AddTclCommand(ZCtrl, ActiveCtrlSet); \
    AddTclCommand(ZCtrl, CtrlListGet); \
    AddTclCommand(ZCtrl, Withdraw); \
    AddTclCommand(ZCtrl, WithdrawRateSet); \
    AddTclCommand(ZCtrl, WithdrawRateGet); \
    AddTclCommand(ZCtrl, LimitsEnabledSet); \
    AddTclCommand(ZCtrl, LimitsEnabledGet); \
    AddTclCommand(ZCtrl, LimitsSet); \
    AddTclCommand(ZCtrl, LimitsGet); \
    AddTclCommand(ZCtrl, StatusGet); \
    AddTclCommand(SafeTip, OnOffSet); \
    AddTclCommand(SafeTip, OnOffGet); \
    AddTclCommand(SafeTip, SignalGet); \
    AddTclCommand(SafeTip, PropsSet); \
    AddTclCommand(SafeTip, PropsGet); \
    AddTclCommand(AutoApproach, Open); \
    AddTclCommand(AutoApproach, OnOffSet); \
    AddTclCommand(AutoApproach, OnOffGet); \
    AddTclCommand(ZSpectr, Open); \
    AddTclCommand(ZSpectr, Start); \
    AddTclCommand(ZSpectr, Stop); \
    AddTclCommand(ZSpectr, StatusGet); \
    AddTclCommand(ZSpectr, ChsSet); \
    AddTclCommand(ZSpectr, ChsGet); \
    AddTclCommand(ZSpectr, PropsSet); \
    AddTclCommand(ZSpectr, PropsGet); \
    AddTclCommand(ZSpectr, AdvPropsSet); \
    AddTclCommand(ZSpectr, AdvPropsGet); \
    AddTclCommand(ZSpectr, RangeSet); \
    AddTclCommand(ZSpectr, RangeGet); \
    AddTclCommand(ZSpectr, TimingSet); \
    AddTclCommand(ZSpectr, TimingGet); \
    AddTclCommand(ZSpectr, RetractDelaySet); \
    AddTclCommand(ZSpectr, RetractDelayGet); \
    AddTclCommand(ZSpectr, RetractSet); \
    AddTclCommand(ZSpectr, RetractGet); \
    AddTclCommand(ZSpectr, Retract2ndSet); \
    AddTclCommand(ZSpectr, Retract2ndGet); \
    AddTclCommand(Piezo, TiltSet); \
    AddTclCommand(Piezo, TiltGet); \
    AddTclCommand(Piezo, RangeSet); \
    AddTclCommand(Piezo, RangeGet); \
    AddTclCommand(Piezo, SensSet); \
    AddTclCommand(Piezo, SensGet); \
    AddTclCommand(Piezo, DriftCompSet); \
    AddTclCommand(Piezo, DriftCompGet); \
    AddTclCommand(Piezo, CalibrGet); \
    AddTclCommand(Piezo, HVAInfoGet); \
    AddTclCommand(Piezo, HVAStatusLEDGet); \
    AddTclCommand(Scan, Action); \
    AddTclCommand(Scan, StatusGet); \
    AddTclCommand(Scan, WaitEndOfScan); \
    AddTclCommand(Scan, FrameSet); \
    AddTclCommand(Scan, FrameGet); \
    AddTclCommand(Scan, BufferSet); \
    AddTclCommand(Scan, BufferGet); \
    AddTclCommand(Scan, PropsSet); \
    AddTclCommand(Scan, PropsGet); \
    AddTclCommand(Scan, SpeedSet); \
    AddTclCommand(Scan, SpeedGet); \
    AddTclCommand(Scan, FrameDataGrab); \
    AddTclCommand(FolMe, XYPosSet); \
    AddTclCommand(FolMe, XYPosGet); \
    AddTclCommand(FolMe, SpeedSet); \
    AddTclCommand(FolMe, SpeedGet); \
    AddTclCommand(FolMe, OversamplSet); \
    AddTclCommand(FolMe, OversamplGet); \
    AddTclCommand(FolMe, Stop); \
    AddTclCommand(FolMe, PSOnOffGet); \
    AddTclCommand(FolMe, PSOnOffSet); \
    AddTclCommand(FolMe, PSExpGet); \
    AddTclCommand(FolMe, PSExpSet); \
    AddTclCommand(FolMe, PSPropsGet); \
    AddTclCommand(FolMe, PSPropsSet); \
    AddTclCommand(TipRec, BufferSizeSet); \
    AddTclCommand(TipRec, BufferSizeGet); \
    AddTclCommand(TipRec, BufferClear); \
    AddTclCommand(TipRec, DataGet); \
    AddTclCommand(TipRec, DataSave); \
    AddTclCommand(Pattern, ExpOpen); \
    AddTclCommand(Pattern, ExpStart); \
    AddTclCommand(Pattern, ExpPause); \
    AddTclCommand(Pattern, ExpStop); \
    AddTclCommand(Pattern, ExpStatusGet); \
    AddTclCommand(Pattern, GridSet); \
    AddTclCommand(Pattern, GridGet); \
    AddTclCommand(Pattern, LineSet); \
    AddTclCommand(Pattern, LineGet); \
    AddTclCommand(Pattern, CloudSet); \
    AddTclCommand(Pattern, CloudGet); \
    AddTclCommand(Pattern, PropsSet); \
    AddTclCommand(Pattern, PropsGet); \
    AddTclCommand(Marks, PointDraw); \
    AddTclCommand(Marks, PointsDraw); \
    AddTclCommand(Marks, LineDraw); \
    AddTclCommand(Marks, LinesDraw); \
    AddTclCommand(Marks, PointsErase); \
    AddTclCommand(Marks, LinesErase); \
    AddTclCommand(Marks, PointsVisibleSet); \
    AddTclCommand(Marks, LinesVisibleSet); \
    AddTclCommand(Marks, PointsGet); \
    AddTclCommand(Marks, LinesGet); \
    AddTclCommand(TipShaper, Start); \
    AddTclCommand(TipShaper, PropsSet); \
    AddTclCommand(TipShaper, PropsGet); \
    AddTclCommand(Motor, StartMove); \
    AddTclCommand(Motor, StartClosedLoop); \
    AddTclCommand(Motor, StopMove); \
    AddTclCommand(Motor, PosGet); \
    AddTclCommand(Motor, StepCounterGet); \
    AddTclCommand(Motor, FreqAmpGet); \
    AddTclCommand(Motor, FreqAmpSet); \
    AddTclCommand(GenSwp, AcqChsSet); \
    AddTclCommand(GenSwp, AcqChsGet); \
    AddTclCommand(GenSwp, SwpSignalSet); \
    AddTclCommand(GenSwp, SwpSignalGet); \
    AddTclCommand(GenSwp, LimitsSet); \
    AddTclCommand(GenSwp, LimitsGet); \
    AddTclCommand(GenSwp, PropsSet); \
    AddTclCommand(GenSwp, PropsGet); \
    AddTclCommand(GenSwp, Start); \
    AddTclCommand(GenSwp, Stop); \
    AddTclCommand(GenSwp, Open); \
    AddTclCommand(GenPICtrl, OnOffSet); \
    AddTclCommand(GenPICtrl, OnOffGet); \
    AddTclCommand(GenPICtrl, AOValSet); \
    AddTclCommand(GenPICtrl, AOValGet); \
    AddTclCommand(GenPICtrl, AOPropsSet); \
    AddTclCommand(GenPICtrl, AOPropsGet); \
    AddTclCommand(GenPICtrl, ModChSet); \
    AddTclCommand(GenPICtrl, ModChGet); \
    AddTclCommand(GenPICtrl, DemodChSet); \
    AddTclCommand(GenPICtrl, DemodChGet); \
    AddTclCommand(GenPICtrl, PropsSet); \
    AddTclCommand(GenPICtrl, PropsGet); \
    AddTclCommand(AtomTrack, CtrlSet); \
    AddTclCommand(AtomTrack, StatusGet); \
    AddTclCommand(AtomTrack, PropsSet); \
    AddTclCommand(AtomTrack, PropsGet); \
    AddTclCommand(AtomTrack, QuickCompStart); \
    AddTclCommand(AtomTrack, DriftComp); \
    AddTclCommand(LockIn, ModOnOffSet); \
    AddTclCommand(LockIn, ModOnOffGet); \
    AddTclCommand(LockIn, ModSignalSet); \
    AddTclCommand(LockIn, ModSignalGet); \
    AddTclCommand(LockIn, ModPhasRegSet); \
    AddTclCommand(LockIn, ModPhasRegGet); \
    AddTclCommand(LockIn, ModHarmonicSet); \
    AddTclCommand(LockIn, ModHarmonicGet); \
    AddTclCommand(LockIn, ModPhasSet); \
    AddTclCommand(LockIn, ModPhasGet); \
    AddTclCommand(LockIn, ModAmpSet); \
    AddTclCommand(LockIn, ModAmpGet); \
    AddTclCommand(LockIn, ModPhasFreqSet); \
    AddTclCommand(LockIn, ModPhasFreqGet); \
    AddTclCommand(LockIn, DemodSignalSet); \
    AddTclCommand(LockIn, DemodSignalGet); \
    AddTclCommand(LockIn, DemodHarmonicSet); \
    AddTclCommand(LockIn, DemodHarmonicGet); \
    AddTclCommand(LockIn, DemodHPFilterSet); \
    AddTclCommand(LockIn, DemodHPFilterGet); \
    AddTclCommand(LockIn, DemodLPFilterSet); \
    AddTclCommand(LockIn, DemodLPFilterGet); \
    AddTclCommand(LockIn, DemodPhasRegSet); \
    AddTclCommand(LockIn, DemodPhasRegGet); \
    AddTclCommand(LockIn, DemodPhasSet); \
    AddTclCommand(LockIn, DemodPhasGet); \
    AddTclCommand(LockIn, DemodSyncFilterSet); \
    AddTclCommand(LockIn, DemodSyncFilterGet); \
    AddTclCommand(LockIn, DemodRTSignalsSet); \
    AddTclCommand(LockIn, DemodRTSignalsGet); \
    AddTclCommand(LockInFreqSwp, Open); \
    AddTclCommand(LockInFreqSwp, Start); \
    AddTclCommand(LockInFreqSwp, SignalSet); \
    AddTclCommand(LockInFreqSwp, SignalGet); \
    AddTclCommand(LockInFreqSwp, LimitsSet); \
    AddTclCommand(LockInFreqSwp, LimitsGet); \
    AddTclCommand(LockInFreqSwp, PropsSet); \
    AddTclCommand(LockInFreqSwp, PropsGet); \
    AddTclCommand(PLL, InpCalibrSet); \
    AddTclCommand(PLL, InpCalibrGet); \
    AddTclCommand(PLL, InpRangeSet); \
    AddTclCommand(PLL, InpRangeGet); \
    AddTclCommand(PLL, InpPropsSet); \
    AddTclCommand(PLL, InpPropsGet); \
    AddTclCommand(PLL, AddOnOffSet); \
    AddTclCommand(PLL, AddOnOffGet); \
    AddTclCommand(PLL, OutOnOffSet); \
    AddTclCommand(PLL, OutOnOffGet); \
    AddTclCommand(PLL, ExcRangeSet); \
    AddTclCommand(PLL, ExcRangeGet); \
    AddTclCommand(PLL, ExcitationSet); \
    AddTclCommand(PLL, ExcitationGet); \
    AddTclCommand(PLL, AmpCtrlSetpntSet); \
    AddTclCommand(PLL, AmpCtrlSetpntGet); \
    AddTclCommand(PLL, AmpCtrlOnOffSet); \
    AddTclCommand(PLL, AmpCtrlOnOffGet); \
    AddTclCommand(PLL, AmpCtrlGainSet); \
    AddTclCommand(PLL, AmpCtrlGainGet); \
    AddTclCommand(PLL, AmpCtrlBandwidthSet); \
    AddTclCommand(PLL, AmpCtrlBandwidthGet); \
    AddTclCommand(PLL, PhasCtrlOnOffSet); \
    AddTclCommand(PLL, PhasCtrlOnOffGet); \
    AddTclCommand(PLL, PhasCtrlGainSet); \
    AddTclCommand(PLL, PhasCtrlGainGet); \
    AddTclCommand(PLL, PhasCtrlBandwidthSet); \
    AddTclCommand(PLL, PhasCtrlBandwidthGet); \
    AddTclCommand(PLL, FreqRangeSet); \
    AddTclCommand(PLL, FreqRangeGet); \
    AddTclCommand(PLL, CenterFreqSet); \
    AddTclCommand(PLL, CenterFreqGet); \
    AddTclCommand(PLL, FreqShiftSet); \
    AddTclCommand(PLL, FreqShiftGet); \
    AddTclCommand(PLL, FreqShiftAutoCenter); \
    AddTclCommand(PLL, FreqExcOverwriteSet); \
    AddTclCommand(PLL, FreqExcOverwriteGet); \
    AddTclCommand(PLL, DemodInputSet); \
    AddTclCommand(PLL, DemodInputGet); \
    AddTclCommand(PLL, DemodHarmonicSet); \
    AddTclCommand(PLL, DemodHarmonicGet); \
    AddTclCommand(PLL, DemodPhasRefSet); \
    AddTclCommand(PLL, DemodPhasRefGet); \
    AddTclCommand(PLL, DemodFilterSet); \
    AddTclCommand(PLL, DemodFilterGet); \
    AddTclCommand(PLLQCtrl, AccessRequest); \
    AddTclCommand(PLLQCtrl, AccessGet); \
    AddTclCommand(PLLQCtrl, OnOffSet); \
    AddTclCommand(PLLQCtrl, OnOffGet); \
    AddTclCommand(PLLQCtrl, QGainSet); \
    AddTclCommand(PLLQCtrl, QGainGet); \
    AddTclCommand(PLLQCtrl, PhaseSet); \
    AddTclCommand(PLLQCtrl, PhaseGet); \
    AddTclCommand(PLLFreqSwp, Open); \
    AddTclCommand(PLLFreqSwp, ParamsSet); \
    AddTclCommand(PLLFreqSwp, ParamsGet); \
    AddTclCommand(PLLFreqSwp, Start); \
    AddTclCommand(PLLFreqSwp, Stop); \
    AddTclCommand(PLLPhasSwp, Start); \
    AddTclCommand(PLLPhasSwp, Stop); \
    AddTclCommand(PLLSignalAnlzr, Open); \
    AddTclCommand(PLLSignalAnlzr, ChSet); \
    AddTclCommand(PLLSignalAnlzr, ChGet); \
    AddTclCommand(PLLSignalAnlzr, TimebaseSet); \
    AddTclCommand(PLLSignalAnlzr, TimebaseGet); \
    AddTclCommand(PLLSignalAnlzr, TrigAuto); \
    AddTclCommand(PLLSignalAnlzr, TrigRearm); \
    AddTclCommand(PLLSignalAnlzr, TrigSet); \
    AddTclCommand(PLLSignalAnlzr, TrigGet); \
    AddTclCommand(PLLSignalAnlzr, OsciDataGet); \
    AddTclCommand(PLLSignalAnlzr, FFTPropsSet); \
    AddTclCommand(PLLSignalAnlzr, FFTPropsGet); \
    AddTclCommand(PLLSignalAnlzr, FFTAvgRestart); \
    AddTclCommand(PLLSignalAnlzr, FFTDataGet); \
    AddTclCommand(PLLZoomFFT, Open); \
    AddTclCommand(PLLZoomFFT, ChSet); \
    AddTclCommand(PLLZoomFFT, ChGet); \
    AddTclCommand(PLLZoomFFT, AvgRestart); \
    AddTclCommand(PLLZoomFFT, PropsSet); \
    AddTclCommand(PLLZoomFFT, PropsGet); \
    AddTclCommand(PLLZoomFFT, DataGet); \
    AddTclCommand(OCSync, AnglesSet); \
    AddTclCommand(OCSync, AnglesGet); \
    AddTclCommand(OCSync, LinkAnglesSet); \
    AddTclCommand(OCSync, LinkAnglesGet); \
    AddTclCommand(Script, Load); \
    AddTclCommand(Script, Save); \
    AddTclCommand(Script, Deploy); \
    AddTclCommand(Script, Undeploy); \
    AddTclCommand(Script, Run); \
    AddTclCommand(Script, Stop); \
    AddTclCommand(Script, ChsGet); \
    AddTclCommand(Script, ChsSet); \
    AddTclCommand(Script, DataGet); \
    AddTclCommand(Script, Autosave); \
    AddTclCommand(Interf, CtrlOnOffSet); \
    AddTclCommand(Interf, CtrlOnOffGet); \
    AddTclCommand(Interf, CtrlPropsSet); \
    AddTclCommand(Interf, CtrlPropsGet); \
    AddTclCommand(Interf, WPiezoSet); \
    AddTclCommand(Interf, WPiezoGet); \
    AddTclCommand(Interf, ValGet); \
    AddTclCommand(Interf, CtrlCalibrOpen); \
    AddTclCommand(Interf, CtrlReset); \
    AddTclCommand(Interf, CtrlNullDefl); \
    AddTclCommand(Laser, OnOffSet); \
    AddTclCommand(Laser, OnOffGet); \
    AddTclCommand(Laser, PropsSet); \
    AddTclCommand(Laser, PropsGet); \
    AddTclCommand(Laser, PowerGet); \
    AddTclCommand(BeamDefl, HorConfigSet); \
    AddTclCommand(BeamDefl, HorConfigGet); \
    AddTclCommand(BeamDefl, VerConfigSet); \
    AddTclCommand(BeamDefl, VerConfigGet); \
    AddTclCommand(BeamDefl, IntConfigSet); \
    AddTclCommand(BeamDefl, IntConfigGet); \
    AddTclCommand(BeamDefl, AutoOffset); \
    AddTclCommand(Signals, NamesGet); \
    AddTclCommand(Signals, InSlotSet); \
    AddTclCommand(Signals, InSlotsGet); \
    AddTclCommand(Signals, CalibrGet); \
    AddTclCommand(Signals, RangeGet); \
    AddTclCommand(Signals, ValGet); \
    AddTclCommand(Signals, ValsGet); \
    AddTclCommand(Signals, MeasNamesGet); \
    AddTclCommand(Signals, AddRTGet); \
    AddTclCommand(Signals, AddRTSet); \
    AddTclCommand(UserIn, CalibrSet); \
    AddTclCommand(UserOut, ModeSet); \
    AddTclCommand(UserOut, ModeGet); \
    AddTclCommand(UserOut, MonitorChSet); \
    AddTclCommand(UserOut, MonitorChGet); \
    AddTclCommand(UserOut, ValSet); \
    AddTclCommand(UserOut, CalibrSet); \
    AddTclCommand(UserOut, CalcSignalNameSet); \
    AddTclCommand(UserOut, CalcSignalNameGet); \
    AddTclCommand(UserOut, CalcSignalConfigSet); \
    AddTclCommand(UserOut, CalcSignalConfigGet); \
    AddTclCommand(UserOut, LimitsSet); \
    AddTclCommand(UserOut, LimitsGet); \
    AddTclCommand(DigLines, PropsSet); \
    AddTclCommand(DigLines, OutStatusSet); \
    AddTclCommand(DigLines, TTLValGet); \
    AddTclCommand(DigLines, Pulse); \
    AddTclCommand(DataLog, Open); \
    AddTclCommand(DataLog, Start); \
    AddTclCommand(DataLog, Stop); \
    AddTclCommand(DataLog, StatusGet); \
    AddTclCommand(DataLog, ChsSet); \
    AddTclCommand(DataLog, ChsGet); \
    AddTclCommand(DataLog, PropsSet); \
    AddTclCommand(DataLog, PropsGet); \
    AddTclCommand(TCPLog, Start); \
    AddTclCommand(TCPLog, Stop); \
    AddTclCommand(TCPLog, ChsSet); \
    AddTclCommand(TCPLog, OversamplSet); \
    AddTclCommand(TCPLog, StatusGet); \
    AddTclCommand(OsciHR, ChSet); \
    AddTclCommand(OsciHR, ChGet); \
    AddTclCommand(OsciHR, OversamplSet); \
    AddTclCommand(OsciHR, OversamplGet); \
    AddTclCommand(OsciHR, CalibrModeSet); \
    AddTclCommand(OsciHR, CalibrModeGet); \
    AddTclCommand(OsciHR, SamplesSet); \
    AddTclCommand(OsciHR, SamplesGet); \
    AddTclCommand(OsciHR, PreTrigSet); \
    AddTclCommand(OsciHR, PreTrigGet); \
    AddTclCommand(OsciHR, Run); \
    AddTclCommand(OsciHR, OsciDataGet); \
    AddTclCommand(OsciHR, TrigModeSet); \
    AddTclCommand(OsciHR, TrigModeGet); \
    AddTclCommand(OsciHR, TrigLevChSet); \
    AddTclCommand(OsciHR, TrigLevChGet); \
    AddTclCommand(OsciHR, TrigLevValSet); \
    AddTclCommand(OsciHR, TrigLevValGet); \
    AddTclCommand(OsciHR, TrigLevHystSet); \
    AddTclCommand(OsciHR, TrigLevHystGet); \
    AddTclCommand(OsciHR, TrigLevSlopeSet); \
    AddTclCommand(OsciHR, TrigLevSlopeGet); \
    AddTclCommand(OsciHR, TrigDigChSet); \
    AddTclCommand(OsciHR, TrigDigChGet); \
    AddTclCommand(OsciHR, TrigArmModeSet); \
    AddTclCommand(OsciHR, TrigArmModeGet); \
    AddTclCommand(OsciHR, TrigDigSlopeSet); \
    AddTclCommand(OsciHR, TrigDigSlopeGet); \
    AddTclCommand(OsciHR, TrigRearm); \
    AddTclCommand(OsciHR, PSDShow); \
    AddTclCommand(OsciHR, PSDWeightSet); \
    AddTclCommand(OsciHR, PSDWeightGet); \
    AddTclCommand(OsciHR, PSDWindowSet); \
    AddTclCommand(OsciHR, PSDWindowGet); \
    AddTclCommand(OsciHR, PSDAvrgTypeSet); \
    AddTclCommand(OsciHR, PSDAvrgTypeGet); \
    AddTclCommand(OsciHR, PSDAvrgCountSet); \
    AddTclCommand(OsciHR, PSDAvrgCountGet); \
    AddTclCommand(OsciHR, PSDAvrgRestart); \
    AddTclCommand(OsciHR, PSDDataGet); \
    AddTclCommand(Osci1T, ChSet); \
    AddTclCommand(Osci1T, ChGet); \
    AddTclCommand(Osci1T, TimebaseSet); \
    AddTclCommand(Osci1T, TimebaseGet); \
    AddTclCommand(Osci1T, TrigSet); \
    AddTclCommand(Osci1T, TrigGet); \
    AddTclCommand(Osci1T, Run); \
    AddTclCommand(Osci1T, DataGet); \
    AddTclCommand(Osci2T, ChsSet); \
    AddTclCommand(Osci2T, ChsGet); \
    AddTclCommand(Osci2T, TimebaseSet); \
    AddTclCommand(Osci2T, TimebaseGet); \
    AddTclCommand(Osci2T, OversamplSet); \
    AddTclCommand(Osci2T, OversamplGet); \
    AddTclCommand(Osci2T, TrigSet); \
    AddTclCommand(Osci2T, TrigGet); \
    AddTclCommand(Osci2T, Run); \
    AddTclCommand(Osci2T, DataGet); \
    AddTclCommand(SignalChart, Open); \
    AddTclCommand(SignalChart, ChsSet); \
    AddTclCommand(SignalChart, ChsGet); \
    AddTclCommand(SpectrumAnlzr, ChSet); \
    AddTclCommand(SpectrumAnlzr, ChGet); \
    AddTclCommand(SpectrumAnlzr, FreqRangeSet); \
    AddTclCommand(SpectrumAnlzr, FreqRangeGet); \
    AddTclCommand(SpectrumAnlzr, FreqResSet); \
    AddTclCommand(SpectrumAnlzr, FreqResGet); \
    AddTclCommand(SpectrumAnlzr, FFTWindowSet); \
    AddTclCommand(SpectrumAnlzr, FFTWindowGet); \
    AddTclCommand(SpectrumAnlzr, AveragSet); \
    AddTclCommand(SpectrumAnlzr, AveragGet); \
    AddTclCommand(SpectrumAnlzr, ACCouplingSet); \
    AddTclCommand(SpectrumAnlzr, ACCouplingGet); \
    AddTclCommand(SpectrumAnlzr, CursorPosSet); \
    AddTclCommand(SpectrumAnlzr, CursorPosGet); \
    AddTclCommand(SpectrumAnlzr, BandRMSGet); \
    AddTclCommand(SpectrumAnlzr, DCGet); \
    AddTclCommand(SpectrumAnlzr, Run); \
    AddTclCommand(SpectrumAnlzr, DataGet); \
    AddTclCommand(FunGen1Ch, Start); \
    AddTclCommand(FunGen1Ch, Stop); \
    AddTclCommand(FunGen1Ch, StatusGet); \
    AddTclCommand(FunGen1Ch, PropsSet); \
    AddTclCommand(FunGen1Ch, PropsGet); \
    AddTclCommand(FunGen1Ch, IdleSet); \
    AddTclCommand(FunGen1Ch, IdleGet); \
    AddTclCommand(FunGen2Ch, Start); \
    AddTclCommand(FunGen2Ch, Stop); \
    AddTclCommand(FunGen2Ch, StatusGet); \
    AddTclCommand(FunGen2Ch, IdleSet); \
    AddTclCommand(FunGen2Ch, IdleGet); \
    AddTclCommand(FunGen2Ch, OnOffSet); \
    AddTclCommand(FunGen2Ch, OnOffGet); \
    AddTclCommand(FunGen2Ch, SignalSet); \
    AddTclCommand(FunGen2Ch, SignalGet); \
    AddTclCommand(FunGen2Ch, PropsSet); \
    AddTclCommand(FunGen2Ch, PropsGet); \
    AddTclCommand(FunGen2Ch, WaveformSet); \
    AddTclCommand(FunGen2Ch, WaveformGet); \
    AddTclCommand(Util, SessionPathGet); \
    AddTclCommand(Util, SettingsLoad); \
    AddTclCommand(Util, SettingsSave); \
    AddTclCommand(Util, LayoutLoad); \
    AddTclCommand(Util, LayoutSave); \
    AddTclCommand(Util, Lock); \
    AddTclCommand(Util, UnLock); \
    AddTclCommand(Util, RTFreqSet); \
    AddTclCommand(Util, RTFreqGet); \
    AddTclCommand(Util, AcqPeriodSet); \
    AddTclCommand(Util, AcqPeriodGet); \
    AddTclCommand(Util, RTOversamplSet); \
    AddTclCommand(Util, RTOversamplGet); \
    AddTclCommand(Util, Quit);

#define RegisterTclCommands \
    RegisterTclCommand(Bias, Set); \
    RegisterTclCommand(Bias, Get); \
    RegisterTclCommand(Bias, RangeSet); \
    RegisterTclCommand(Bias, RangeGet); \
    RegisterTclCommand(Bias, CalibrSet); \
    RegisterTclCommand(Bias, CalibrGet); \
    RegisterTclCommand(Bias, Pulse); \
    RegisterTclCommand(BiasSwp, Open); \
    RegisterTclCommand(BiasSwp, Start); \
    RegisterTclCommand(BiasSwp, PropsSet); \
    RegisterTclCommand(BiasSwp, LimitsSet); \
    RegisterTclCommand(BiasSpectr, PropsGet); \
    RegisterTclCommand(BiasSpectr, AdvPropsSet); \
    RegisterTclCommand(BiasSpectr, AdvPropsGet); \
    RegisterTclCommand(BiasSpectr, LimitsSet); \
    RegisterTclCommand(BiasSpectr, LimitsGet); \
    RegisterTclCommand(BiasSpectr, TimingSet); \
    RegisterTclCommand(BiasSpectr, TimingGet); \
    RegisterTclCommand(BiasSpectr, TTLSyncSet); \
    RegisterTclCommand(BiasSpectr, TTLSyncGet); \
    RegisterTclCommand(BiasSpectr, AltZCtrlSet); \
    RegisterTclCommand(BiasSpectr, AltZCtrlGet); \
    RegisterTclCommand(BiasSpectr, MLSLockinPerSegSet); \
    RegisterTclCommand(BiasSpectr, MLSLockinPerSegGet); \
    RegisterTclCommand(BiasSpectr, MLSModeSet); \
    RegisterTclCommand(BiasSpectr, MLSModeGet); \
    RegisterTclCommand(BiasSpectr, MLSValsSet); \
    RegisterTclCommand(BiasSpectr, MLSValsGet); \
    RegisterTclCommand(KelvinCtrl, CtrlOnOffSet); \
    RegisterTclCommand(KelvinCtrl, CtrlOnOffGet); \
    RegisterTclCommand(KelvinCtrl, SetpntSet); \
    RegisterTclCommand(KelvinCtrl, SetpntGet); \
    RegisterTclCommand(KelvinCtrl, GainSet); \
    RegisterTclCommand(KelvinCtrl, GainGet); \
    RegisterTclCommand(KelvinCtrl, ModParamsSet); \
    RegisterTclCommand(KelvinCtrl, ModParamsGet); \
    RegisterTclCommand(KelvinCtrl, ModOnOffSet); \
    RegisterTclCommand(KelvinCtrl, ModOnOffGet); \
    RegisterTclCommand(KelvinCtrl, CtrlSignalSet); \
    RegisterTclCommand(KelvinCtrl, CtrlSignalGet); \
    RegisterTclCommand(KelvinCtrl, AmpGet); \
    RegisterTclCommand(KelvinCtrl, BiasLimitsSet); \
    RegisterTclCommand(KelvinCtrl, BiasLimitsGet); \
    RegisterTclCommand(CPDComp, Open); \
    RegisterTclCommand(CPDComp, Close); \
    RegisterTclCommand(CPDComp, ParamsSet); \
    RegisterTclCommand(CPDComp, ParamsGet); \
    RegisterTclCommand(CPDComp, DataGet); \
    RegisterTclCommand(Current, Get); \
    RegisterTclCommand(Current, Get100); \
    RegisterTclCommand(Current, BEEMGet); \
    RegisterTclCommand(Current, GainSet); \
    RegisterTclCommand(Current, GainsGet); \
    RegisterTclCommand(Current, CalibrSet); \
    RegisterTclCommand(Current, CalibrGet); \
    RegisterTclCommand(ZCtrl, ZPosSet); \
    RegisterTclCommand(ZCtrl, ZPosGet); \
    RegisterTclCommand(ZCtrl, OnOffSet); \
    RegisterTclCommand(ZCtrl, OnOffGet); \
    RegisterTclCommand(ZCtrl, SetpntSet); \
    RegisterTclCommand(ZCtrl, SetpntGet); \
    RegisterTclCommand(ZCtrl, GainSet); \
    RegisterTclCommand(ZCtrl, GainGet); \
    RegisterTclCommand(ZCtrl, SwitchOffDelaySet); \
    RegisterTclCommand(ZCtrl, SwitchOffDelayGet); \
    RegisterTclCommand(ZCtrl, TipLiftSet); \
    RegisterTclCommand(ZCtrl, TipLiftGet); \
    RegisterTclCommand(ZCtrl, Home); \
    RegisterTclCommand(ZCtrl, HomePropsSet); \
    RegisterTclCommand(ZCtrl, HomePropsGet); \
    RegisterTclCommand(ZCtrl, ActiveCtrlSet); \
    RegisterTclCommand(ZCtrl, CtrlListGet); \
    RegisterTclCommand(ZCtrl, Withdraw); \
    RegisterTclCommand(ZCtrl, WithdrawRateSet); \
    RegisterTclCommand(ZCtrl, WithdrawRateGet); \
    RegisterTclCommand(ZCtrl, LimitsEnabledSet); \
    RegisterTclCommand(ZCtrl, LimitsEnabledGet); \
    RegisterTclCommand(ZCtrl, LimitsSet); \
    RegisterTclCommand(ZCtrl, LimitsGet); \
    RegisterTclCommand(ZCtrl, StatusGet); \
    RegisterTclCommand(SafeTip, OnOffSet); \
    RegisterTclCommand(SafeTip, OnOffGet); \
    RegisterTclCommand(SafeTip, SignalGet); \
    RegisterTclCommand(SafeTip, PropsSet); \
    RegisterTclCommand(SafeTip, PropsGet); \
    RegisterTclCommand(AutoApproach, Open); \
    RegisterTclCommand(AutoApproach, OnOffSet); \
    RegisterTclCommand(AutoApproach, OnOffGet); \
    RegisterTclCommand(ZSpectr, Open); \
    RegisterTclCommand(ZSpectr, Start); \
    RegisterTclCommand(ZSpectr, Stop); \
    RegisterTclCommand(ZSpectr, StatusGet); \
    RegisterTclCommand(ZSpectr, ChsSet); \
    RegisterTclCommand(ZSpectr, ChsGet); \
    RegisterTclCommand(ZSpectr, PropsSet); \
    RegisterTclCommand(ZSpectr, PropsGet); \
    RegisterTclCommand(ZSpectr, AdvPropsSet); \
    RegisterTclCommand(ZSpectr, AdvPropsGet); \
    RegisterTclCommand(ZSpectr, RangeSet); \
    RegisterTclCommand(ZSpectr, RangeGet); \
    RegisterTclCommand(ZSpectr, TimingSet); \
    RegisterTclCommand(ZSpectr, TimingGet); \
    RegisterTclCommand(ZSpectr, RetractDelaySet); \
    RegisterTclCommand(ZSpectr, RetractDelayGet); \
    RegisterTclCommand(ZSpectr, RetractSet); \
    RegisterTclCommand(ZSpectr, RetractGet); \
    RegisterTclCommand(ZSpectr, Retract2ndSet); \
    RegisterTclCommand(ZSpectr, Retract2ndGet); \
    RegisterTclCommand(Piezo, TiltSet); \
    RegisterTclCommand(Piezo, TiltGet); \
    RegisterTclCommand(Piezo, RangeSet); \
    RegisterTclCommand(Piezo, RangeGet); \
    RegisterTclCommand(Piezo, SensSet); \
    RegisterTclCommand(Piezo, SensGet); \
    RegisterTclCommand(Piezo, DriftCompSet); \
    RegisterTclCommand(Piezo, DriftCompGet); \
    RegisterTclCommand(Piezo, CalibrGet); \
    RegisterTclCommand(Piezo, HVAInfoGet); \
    RegisterTclCommand(Piezo, HVAStatusLEDGet); \
    RegisterTclCommand(Scan, Action); \
    RegisterTclCommand(Scan, StatusGet); \
    RegisterTclCommand(Scan, WaitEndOfScan); \
    RegisterTclCommand(Scan, FrameSet); \
    RegisterTclCommand(Scan, FrameGet); \
    RegisterTclCommand(Scan, BufferSet); \
    RegisterTclCommand(Scan, BufferGet); \
    RegisterTclCommand(Scan, PropsSet); \
    RegisterTclCommand(Scan, PropsGet); \
    RegisterTclCommand(Scan, SpeedSet); \
    RegisterTclCommand(Scan, SpeedGet); \
    RegisterTclCommand(Scan, FrameDataGrab); \
    RegisterTclCommand(FolMe, XYPosSet); \
    RegisterTclCommand(FolMe, XYPosGet); \
    RegisterTclCommand(FolMe, SpeedSet); \
    RegisterTclCommand(FolMe, SpeedGet); \
    RegisterTclCommand(FolMe, OversamplSet); \
    RegisterTclCommand(FolMe, OversamplGet); \
    RegisterTclCommand(FolMe, Stop); \
    RegisterTclCommand(FolMe, PSOnOffGet); \
    RegisterTclCommand(FolMe, PSOnOffSet); \
    RegisterTclCommand(FolMe, PSExpGet); \
    RegisterTclCommand(FolMe, PSExpSet); \
    RegisterTclCommand(FolMe, PSPropsGet); \
    RegisterTclCommand(FolMe, PSPropsSet); \
    RegisterTclCommand(TipRec, BufferSizeSet); \
    RegisterTclCommand(TipRec, BufferSizeGet); \
    RegisterTclCommand(TipRec, BufferClear); \
    RegisterTclCommand(TipRec, DataGet); \
    RegisterTclCommand(TipRec, DataSave); \
    RegisterTclCommand(Pattern, ExpOpen); \
    RegisterTclCommand(Pattern, ExpStart); \
    RegisterTclCommand(Pattern, ExpPause); \
    RegisterTclCommand(Pattern, ExpStop); \
    RegisterTclCommand(Pattern, ExpStatusGet); \
    RegisterTclCommand(Pattern, GridSet); \
    RegisterTclCommand(Pattern, GridGet); \
    RegisterTclCommand(Pattern, LineSet); \
    RegisterTclCommand(Pattern, LineGet); \
    RegisterTclCommand(Pattern, CloudSet); \
    RegisterTclCommand(Pattern, CloudGet); \
    RegisterTclCommand(Pattern, PropsSet); \
    RegisterTclCommand(Pattern, PropsGet); \
    RegisterTclCommand(Marks, PointDraw); \
    RegisterTclCommand(Marks, PointsDraw); \
    RegisterTclCommand(Marks, LineDraw); \
    RegisterTclCommand(Marks, LinesDraw); \
    RegisterTclCommand(Marks, PointsErase); \
    RegisterTclCommand(Marks, LinesErase); \
    RegisterTclCommand(Marks, PointsVisibleSet); \
    RegisterTclCommand(Marks, LinesVisibleSet); \
    RegisterTclCommand(Marks, PointsGet); \
    RegisterTclCommand(Marks, LinesGet); \
    RegisterTclCommand(TipShaper, Start); \
    RegisterTclCommand(TipShaper, PropsSet); \
    RegisterTclCommand(TipShaper, PropsGet); \
    RegisterTclCommand(Motor, StartMove); \
    RegisterTclCommand(Motor, StartClosedLoop); \
    RegisterTclCommand(Motor, StopMove); \
    RegisterTclCommand(Motor, PosGet); \
    RegisterTclCommand(Motor, StepCounterGet); \
    RegisterTclCommand(Motor, FreqAmpGet); \
    RegisterTclCommand(Motor, FreqAmpSet); \
    RegisterTclCommand(GenSwp, AcqChsSet); \
    RegisterTclCommand(GenSwp, AcqChsGet); \
    RegisterTclCommand(GenSwp, SwpSignalSet); \
    RegisterTclCommand(GenSwp, SwpSignalGet); \
    RegisterTclCommand(GenSwp, LimitsSet); \
    RegisterTclCommand(GenSwp, LimitsGet); \
    RegisterTclCommand(GenSwp, PropsSet); \
    RegisterTclCommand(GenSwp, PropsGet); \
    RegisterTclCommand(GenSwp, Start); \
    RegisterTclCommand(GenSwp, Stop); \
    RegisterTclCommand(GenSwp, Open); \
    RegisterTclCommand(GenPICtrl, OnOffSet); \
    RegisterTclCommand(GenPICtrl, OnOffGet); \
    RegisterTclCommand(GenPICtrl, AOValSet); \
    RegisterTclCommand(GenPICtrl, AOValGet); \
    RegisterTclCommand(GenPICtrl, AOPropsSet); \
    RegisterTclCommand(GenPICtrl, AOPropsGet); \
    RegisterTclCommand(GenPICtrl, ModChSet); \
    RegisterTclCommand(GenPICtrl, ModChGet); \
    RegisterTclCommand(GenPICtrl, DemodChSet); \
    RegisterTclCommand(GenPICtrl, DemodChGet); \
    RegisterTclCommand(GenPICtrl, PropsSet); \
    RegisterTclCommand(GenPICtrl, PropsGet); \
    RegisterTclCommand(AtomTrack, CtrlSet); \
    RegisterTclCommand(AtomTrack, StatusGet); \
    RegisterTclCommand(AtomTrack, PropsSet); \
    RegisterTclCommand(AtomTrack, PropsGet); \
    RegisterTclCommand(AtomTrack, QuickCompStart); \
    RegisterTclCommand(AtomTrack, DriftComp); \
    RegisterTclCommand(LockIn, ModOnOffSet); \
    RegisterTclCommand(LockIn, ModOnOffGet); \
    RegisterTclCommand(LockIn, ModSignalSet); \
    RegisterTclCommand(LockIn, ModSignalGet); \
    RegisterTclCommand(LockIn, ModPhasRegSet); \
    RegisterTclCommand(LockIn, ModPhasRegGet); \
    RegisterTclCommand(LockIn, ModHarmonicSet); \
    RegisterTclCommand(LockIn, ModHarmonicGet); \
    RegisterTclCommand(LockIn, ModPhasSet); \
    RegisterTclCommand(LockIn, ModPhasGet); \
    RegisterTclCommand(LockIn, ModAmpSet); \
    RegisterTclCommand(LockIn, ModAmpGet); \
    RegisterTclCommand(LockIn, ModPhasFreqSet); \
    RegisterTclCommand(LockIn, ModPhasFreqGet); \
    RegisterTclCommand(LockIn, DemodSignalSet); \
    RegisterTclCommand(LockIn, DemodSignalGet); \
    RegisterTclCommand(LockIn, DemodHarmonicSet); \
    RegisterTclCommand(LockIn, DemodHarmonicGet); \
    RegisterTclCommand(LockIn, DemodHPFilterSet); \
    RegisterTclCommand(LockIn, DemodHPFilterGet); \
    RegisterTclCommand(LockIn, DemodLPFilterSet); \
    RegisterTclCommand(LockIn, DemodLPFilterGet); \
    RegisterTclCommand(LockIn, DemodPhasRegSet); \
    RegisterTclCommand(LockIn, DemodPhasRegGet); \
    RegisterTclCommand(LockIn, DemodPhasSet); \
    RegisterTclCommand(LockIn, DemodPhasGet); \
    RegisterTclCommand(LockIn, DemodSyncFilterSet); \
    RegisterTclCommand(LockIn, DemodSyncFilterGet); \
    RegisterTclCommand(LockIn, DemodRTSignalsSet); \
    RegisterTclCommand(LockIn, DemodRTSignalsGet); \
    RegisterTclCommand(LockInFreqSwp, Open); \
    RegisterTclCommand(LockInFreqSwp, Start); \
    RegisterTclCommand(LockInFreqSwp, SignalSet); \
    RegisterTclCommand(LockInFreqSwp, SignalGet); \
    RegisterTclCommand(LockInFreqSwp, LimitsSet); \
    RegisterTclCommand(LockInFreqSwp, LimitsGet); \
    RegisterTclCommand(LockInFreqSwp, PropsSet); \
    RegisterTclCommand(LockInFreqSwp, PropsGet); \
    RegisterTclCommand(PLL, InpCalibrSet); \
    RegisterTclCommand(PLL, InpCalibrGet); \
    RegisterTclCommand(PLL, InpRangeSet); \
    RegisterTclCommand(PLL, InpRangeGet); \
    RegisterTclCommand(PLL, InpPropsSet); \
    RegisterTclCommand(PLL, InpPropsGet); \
    RegisterTclCommand(PLL, AddOnOffSet); \
    RegisterTclCommand(PLL, AddOnOffGet); \
    RegisterTclCommand(PLL, OutOnOffSet); \
    RegisterTclCommand(PLL, OutOnOffGet); \
    RegisterTclCommand(PLL, ExcRangeSet); \
    RegisterTclCommand(PLL, ExcRangeGet); \
    RegisterTclCommand(PLL, ExcitationSet); \
    RegisterTclCommand(PLL, ExcitationGet); \
    RegisterTclCommand(PLL, AmpCtrlSetpntSet); \
    RegisterTclCommand(PLL, AmpCtrlSetpntGet); \
    RegisterTclCommand(PLL, AmpCtrlOnOffSet); \
    RegisterTclCommand(PLL, AmpCtrlOnOffGet); \
    RegisterTclCommand(PLL, AmpCtrlGainSet); \
    RegisterTclCommand(PLL, AmpCtrlGainGet); \
    RegisterTclCommand(PLL, AmpCtrlBandwidthSet); \
    RegisterTclCommand(PLL, AmpCtrlBandwidthGet); \
    RegisterTclCommand(PLL, PhasCtrlOnOffSet); \
    RegisterTclCommand(PLL, PhasCtrlOnOffGet); \
    RegisterTclCommand(PLL, PhasCtrlGainSet); \
    RegisterTclCommand(PLL, PhasCtrlGainGet); \
    RegisterTclCommand(PLL, PhasCtrlBandwidthSet); \
    RegisterTclCommand(PLL, PhasCtrlBandwidthGet); \
    RegisterTclCommand(PLL, FreqRangeSet); \
    RegisterTclCommand(PLL, FreqRangeGet); \
    RegisterTclCommand(PLL, CenterFreqSet); \
    RegisterTclCommand(PLL, CenterFreqGet); \
    RegisterTclCommand(PLL, FreqShiftSet); \
    RegisterTclCommand(PLL, FreqShiftGet); \
    RegisterTclCommand(PLL, FreqShiftAutoCenter); \
    RegisterTclCommand(PLL, FreqExcOverwriteSet); \
    RegisterTclCommand(PLL, FreqExcOverwriteGet); \
    RegisterTclCommand(PLL, DemodInputSet); \
    RegisterTclCommand(PLL, DemodInputGet); \
    RegisterTclCommand(PLL, DemodHarmonicSet); \
    RegisterTclCommand(PLL, DemodHarmonicGet); \
    RegisterTclCommand(PLL, DemodPhasRefSet); \
    RegisterTclCommand(PLL, DemodPhasRefGet); \
    RegisterTclCommand(PLL, DemodFilterSet); \
    RegisterTclCommand(PLL, DemodFilterGet); \
    RegisterTclCommand(PLLQCtrl, AccessRequest); \
    RegisterTclCommand(PLLQCtrl, AccessGet); \
    RegisterTclCommand(PLLQCtrl, OnOffSet); \
    RegisterTclCommand(PLLQCtrl, OnOffGet); \
    RegisterTclCommand(PLLQCtrl, QGainSet); \
    RegisterTclCommand(PLLQCtrl, QGainGet); \
    RegisterTclCommand(PLLQCtrl, PhaseSet); \
    RegisterTclCommand(PLLQCtrl, PhaseGet); \
    RegisterTclCommand(PLLFreqSwp, Open); \
    RegisterTclCommand(PLLFreqSwp, ParamsSet); \
    RegisterTclCommand(PLLFreqSwp, ParamsGet); \
    RegisterTclCommand(PLLFreqSwp, Start); \
    RegisterTclCommand(PLLFreqSwp, Stop); \
    RegisterTclCommand(PLLPhasSwp, Start); \
    RegisterTclCommand(PLLPhasSwp, Stop); \
    RegisterTclCommand(PLLSignalAnlzr, Open); \
    RegisterTclCommand(PLLSignalAnlzr, ChSet); \
    RegisterTclCommand(PLLSignalAnlzr, ChGet); \
    RegisterTclCommand(PLLSignalAnlzr, TimebaseSet); \
    RegisterTclCommand(PLLSignalAnlzr, TimebaseGet); \
    RegisterTclCommand(PLLSignalAnlzr, TrigAuto); \
    RegisterTclCommand(PLLSignalAnlzr, TrigRearm); \
    RegisterTclCommand(PLLSignalAnlzr, TrigSet); \
    RegisterTclCommand(PLLSignalAnlzr, TrigGet); \
    RegisterTclCommand(PLLSignalAnlzr, OsciDataGet); \
    RegisterTclCommand(PLLSignalAnlzr, FFTPropsSet); \
    RegisterTclCommand(PLLSignalAnlzr, FFTPropsGet); \
    RegisterTclCommand(PLLSignalAnlzr, FFTAvgRestart); \
    RegisterTclCommand(PLLSignalAnlzr, FFTDataGet); \
    RegisterTclCommand(PLLZoomFFT, Open); \
    RegisterTclCommand(PLLZoomFFT, ChSet); \
    RegisterTclCommand(PLLZoomFFT, ChGet); \
    RegisterTclCommand(PLLZoomFFT, AvgRestart); \
    RegisterTclCommand(PLLZoomFFT, PropsSet); \
    RegisterTclCommand(PLLZoomFFT, PropsGet); \
    RegisterTclCommand(PLLZoomFFT, DataGet); \
    RegisterTclCommand(OCSync, AnglesSet); \
    RegisterTclCommand(OCSync, AnglesGet); \
    RegisterTclCommand(OCSync, LinkAnglesSet); \
    RegisterTclCommand(OCSync, LinkAnglesGet); \
    RegisterTclCommand(Script, Load); \
    RegisterTclCommand(Script, Save); \
    RegisterTclCommand(Script, Deploy); \
    RegisterTclCommand(Script, Undeploy); \
    RegisterTclCommand(Script, Run); \
    RegisterTclCommand(Script, Stop); \
    RegisterTclCommand(Script, ChsGet); \
    RegisterTclCommand(Script, ChsSet); \
    RegisterTclCommand(Script, DataGet); \
    RegisterTclCommand(Script, Autosave); \
    RegisterTclCommand(Interf, CtrlOnOffSet); \
    RegisterTclCommand(Interf, CtrlOnOffGet); \
    RegisterTclCommand(Interf, CtrlPropsSet); \
    RegisterTclCommand(Interf, CtrlPropsGet); \
    RegisterTclCommand(Interf, WPiezoSet); \
    RegisterTclCommand(Interf, WPiezoGet); \
    RegisterTclCommand(Interf, ValGet); \
    RegisterTclCommand(Interf, CtrlCalibrOpen); \
    RegisterTclCommand(Interf, CtrlReset); \
    RegisterTclCommand(Interf, CtrlNullDefl); \
    RegisterTclCommand(Laser, OnOffSet); \
    RegisterTclCommand(Laser, OnOffGet); \
    RegisterTclCommand(Laser, PropsSet); \
    RegisterTclCommand(Laser, PropsGet); \
    RegisterTclCommand(Laser, PowerGet); \
    RegisterTclCommand(BeamDefl, HorConfigSet); \
    RegisterTclCommand(BeamDefl, HorConfigGet); \
    RegisterTclCommand(BeamDefl, VerConfigSet); \
    RegisterTclCommand(BeamDefl, VerConfigGet); \
    RegisterTclCommand(BeamDefl, IntConfigSet); \
    RegisterTclCommand(BeamDefl, IntConfigGet); \
    RegisterTclCommand(BeamDefl, AutoOffset); \
    RegisterTclCommand(Signals, NamesGet); \
    RegisterTclCommand(Signals, InSlotSet); \
    RegisterTclCommand(Signals, InSlotsGet); \
    RegisterTclCommand(Signals, CalibrGet); \
    RegisterTclCommand(Signals, RangeGet); \
    RegisterTclCommand(Signals, ValGet); \
    RegisterTclCommand(Signals, ValsGet); \
    RegisterTclCommand(Signals, MeasNamesGet); \
    RegisterTclCommand(Signals, AddRTGet); \
    RegisterTclCommand(Signals, AddRTSet); \
    RegisterTclCommand(UserIn, CalibrSet); \
    RegisterTclCommand(UserOut, ModeSet); \
    RegisterTclCommand(UserOut, ModeGet); \
    RegisterTclCommand(UserOut, MonitorChSet); \
    RegisterTclCommand(UserOut, MonitorChGet); \
    RegisterTclCommand(UserOut, ValSet); \
    RegisterTclCommand(UserOut, CalibrSet); \
    RegisterTclCommand(UserOut, CalcSignalNameSet); \
    RegisterTclCommand(UserOut, CalcSignalNameGet); \
    RegisterTclCommand(UserOut, CalcSignalConfigSet); \
    RegisterTclCommand(UserOut, CalcSignalConfigGet); \
    RegisterTclCommand(UserOut, LimitsSet); \
    RegisterTclCommand(UserOut, LimitsGet); \
    RegisterTclCommand(DigLines, PropsSet); \
    RegisterTclCommand(DigLines, OutStatusSet); \
    RegisterTclCommand(DigLines, TTLValGet); \
    RegisterTclCommand(DigLines, Pulse); \
    RegisterTclCommand(DataLog, Open); \
    RegisterTclCommand(DataLog, Start); \
    RegisterTclCommand(DataLog, Stop); \
    RegisterTclCommand(DataLog, StatusGet); \
    RegisterTclCommand(DataLog, ChsSet); \
    RegisterTclCommand(DataLog, ChsGet); \
    RegisterTclCommand(DataLog, PropsSet); \
    RegisterTclCommand(DataLog, PropsGet); \
    RegisterTclCommand(TCPLog, Start); \
    RegisterTclCommand(TCPLog, Stop); \
    RegisterTclCommand(TCPLog, ChsSet); \
    RegisterTclCommand(TCPLog, OversamplSet); \
    RegisterTclCommand(TCPLog, StatusGet); \
    RegisterTclCommand(OsciHR, ChSet); \
    RegisterTclCommand(OsciHR, ChGet); \
    RegisterTclCommand(OsciHR, OversamplSet); \
    RegisterTclCommand(OsciHR, OversamplGet); \
    RegisterTclCommand(OsciHR, CalibrModeSet); \
    RegisterTclCommand(OsciHR, CalibrModeGet); \
    RegisterTclCommand(OsciHR, SamplesSet); \
    RegisterTclCommand(OsciHR, SamplesGet); \
    RegisterTclCommand(OsciHR, PreTrigSet); \
    RegisterTclCommand(OsciHR, PreTrigGet); \
    RegisterTclCommand(OsciHR, Run); \
    RegisterTclCommand(OsciHR, OsciDataGet); \
    RegisterTclCommand(OsciHR, TrigModeSet); \
    RegisterTclCommand(OsciHR, TrigModeGet); \
    RegisterTclCommand(OsciHR, TrigLevChSet); \
    RegisterTclCommand(OsciHR, TrigLevChGet); \
    RegisterTclCommand(OsciHR, TrigLevValSet); \
    RegisterTclCommand(OsciHR, TrigLevValGet); \
    RegisterTclCommand(OsciHR, TrigLevHystSet); \
    RegisterTclCommand(OsciHR, TrigLevHystGet); \
    RegisterTclCommand(OsciHR, TrigLevSlopeSet); \
    RegisterTclCommand(OsciHR, TrigLevSlopeGet); \
    RegisterTclCommand(OsciHR, TrigDigChSet); \
    RegisterTclCommand(OsciHR, TrigDigChGet); \
    RegisterTclCommand(OsciHR, TrigArmModeSet); \
    RegisterTclCommand(OsciHR, TrigArmModeGet); \
    RegisterTclCommand(OsciHR, TrigDigSlopeSet); \
    RegisterTclCommand(OsciHR, TrigDigSlopeGet); \
    RegisterTclCommand(OsciHR, TrigRearm); \
    RegisterTclCommand(OsciHR, PSDShow); \
    RegisterTclCommand(OsciHR, PSDWeightSet); \
    RegisterTclCommand(OsciHR, PSDWeightGet); \
    RegisterTclCommand(OsciHR, PSDWindowSet); \
    RegisterTclCommand(OsciHR, PSDWindowGet); \
    RegisterTclCommand(OsciHR, PSDAvrgTypeSet); \
    RegisterTclCommand(OsciHR, PSDAvrgTypeGet); \
    RegisterTclCommand(OsciHR, PSDAvrgCountSet); \
    RegisterTclCommand(OsciHR, PSDAvrgCountGet); \
    RegisterTclCommand(OsciHR, PSDAvrgRestart); \
    RegisterTclCommand(OsciHR, PSDDataGet); \
    RegisterTclCommand(Osci1T, ChSet); \
    RegisterTclCommand(Osci1T, ChGet); \
    RegisterTclCommand(Osci1T, TimebaseSet); \
    RegisterTclCommand(Osci1T, TimebaseGet); \
    RegisterTclCommand(Osci1T, TrigSet); \
    RegisterTclCommand(Osci1T, TrigGet); \
    RegisterTclCommand(Osci1T, Run); \
    RegisterTclCommand(Osci1T, DataGet); \
    RegisterTclCommand(Osci2T, ChsSet); \
    RegisterTclCommand(Osci2T, ChsGet); \
    RegisterTclCommand(Osci2T, TimebaseSet); \
    RegisterTclCommand(Osci2T, TimebaseGet); \
    RegisterTclCommand(Osci2T, OversamplSet); \
    RegisterTclCommand(Osci2T, OversamplGet); \
    RegisterTclCommand(Osci2T, TrigSet); \
    RegisterTclCommand(Osci2T, TrigGet); \
    RegisterTclCommand(Osci2T, Run); \
    RegisterTclCommand(Osci2T, DataGet); \
    RegisterTclCommand(SignalChart, Open); \
    RegisterTclCommand(SignalChart, ChsSet); \
    RegisterTclCommand(SignalChart, ChsGet); \
    RegisterTclCommand(SpectrumAnlzr, ChSet); \
    RegisterTclCommand(SpectrumAnlzr, ChGet); \
    RegisterTclCommand(SpectrumAnlzr, FreqRangeSet); \
    RegisterTclCommand(SpectrumAnlzr, FreqRangeGet); \
    RegisterTclCommand(SpectrumAnlzr, FreqResSet); \
    RegisterTclCommand(SpectrumAnlzr, FreqResGet); \
    RegisterTclCommand(SpectrumAnlzr, FFTWindowSet); \
    RegisterTclCommand(SpectrumAnlzr, FFTWindowGet); \
    RegisterTclCommand(SpectrumAnlzr, AveragSet); \
    RegisterTclCommand(SpectrumAnlzr, AveragGet); \
    RegisterTclCommand(SpectrumAnlzr, ACCouplingSet); \
    RegisterTclCommand(SpectrumAnlzr, ACCouplingGet); \
    RegisterTclCommand(SpectrumAnlzr, CursorPosSet); \
    RegisterTclCommand(SpectrumAnlzr, CursorPosGet); \
    RegisterTclCommand(SpectrumAnlzr, BandRMSGet); \
    RegisterTclCommand(SpectrumAnlzr, DCGet); \
    RegisterTclCommand(SpectrumAnlzr, Run); \
    RegisterTclCommand(SpectrumAnlzr, DataGet); \
    RegisterTclCommand(FunGen1Ch, Start); \
    RegisterTclCommand(FunGen1Ch, Stop); \
    RegisterTclCommand(FunGen1Ch, StatusGet); \
    RegisterTclCommand(FunGen1Ch, PropsSet); \
    RegisterTclCommand(FunGen1Ch, PropsGet); \
    RegisterTclCommand(FunGen1Ch, IdleSet); \
    RegisterTclCommand(FunGen1Ch, IdleGet); \
    RegisterTclCommand(FunGen2Ch, Start); \
    RegisterTclCommand(FunGen2Ch, Stop); \
    RegisterTclCommand(FunGen2Ch, StatusGet); \
    RegisterTclCommand(FunGen2Ch, IdleSet); \
    RegisterTclCommand(FunGen2Ch, IdleGet); \
    RegisterTclCommand(FunGen2Ch, OnOffSet); \
    RegisterTclCommand(FunGen2Ch, OnOffGet); \
    RegisterTclCommand(FunGen2Ch, SignalSet); \
    RegisterTclCommand(FunGen2Ch, SignalGet); \
    RegisterTclCommand(FunGen2Ch, PropsSet); \
    RegisterTclCommand(FunGen2Ch, PropsGet); \
    RegisterTclCommand(FunGen2Ch, WaveformSet); \
    RegisterTclCommand(FunGen2Ch, WaveformGet); \
    RegisterTclCommand(Util, SessionPathGet); \
    RegisterTclCommand(Util, SettingsLoad); \
    RegisterTclCommand(Util, SettingsSave); \
    RegisterTclCommand(Util, LayoutLoad); \
    RegisterTclCommand(Util, LayoutSave); \
    RegisterTclCommand(Util, Lock); \
    RegisterTclCommand(Util, UnLock); \
    RegisterTclCommand(Util, RTFreqSet); \
    RegisterTclCommand(Util, RTFreqGet); \
    RegisterTclCommand(Util, AcqPeriodSet); \
    RegisterTclCommand(Util, AcqPeriodGet); \
    RegisterTclCommand(Util, RTOversamplSet); \
    RegisterTclCommand(Util, RTOversamplGet); \
    RegisterTclCommand(Util, Quit);

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
    AddCommand(KelvinCtrl, GainGet); \
    AddCommand(KelvinCtrl, ModParamsSet); \
    AddCommand(KelvinCtrl, ModParamsGet); \
    AddCommand(KelvinCtrl, ModOnOffSet); \
    AddCommand(KelvinCtrl, ModOnOffGet); \
    AddCommand(KelvinCtrl, CtrlSignalSet); \
    AddCommand(KelvinCtrl, CtrlSignalGet); \
    AddCommand(KelvinCtrl, AmpGet); \
    AddCommand(KelvinCtrl, BiasLimitsSet); \
    AddCommand(KelvinCtrl, BiasLimitsGet); \
    AddCommand(CPDComp, Open); \
    AddCommand(CPDComp, Close); \
    AddCommand(CPDComp, ParamsSet); \
    AddCommand(CPDComp, ParamsGet); \
    AddCommand(CPDComp, DataGet); \
    AddCommand(Current, Get); \
    AddCommand(Current, Get100); \
    AddCommand(Current, BEEMGet); \
    AddCommand(Current, GainSet); \
    AddCommand(Current, GainsGet); \
    AddCommand(Current, CalibrSet); \
    AddCommand(Current, CalibrGet); \
    AddCommand(ZCtrl, ZPosSet); \
    AddCommand(ZCtrl, ZPosGet); \
    AddCommand(ZCtrl, OnOffSet); \
    AddCommand(ZCtrl, OnOffGet); \
    AddCommand(ZCtrl, SetpntSet); \
    AddCommand(ZCtrl, SetpntGet); \
    AddCommand(ZCtrl, GainSet); \
    AddCommand(ZCtrl, GainGet); \
    AddCommand(ZCtrl, SwitchOffDelaySet); \
    AddCommand(ZCtrl, SwitchOffDelayGet); \
    AddCommand(ZCtrl, TipLiftSet); \
    AddCommand(ZCtrl, TipLiftGet); \
    AddCommand(ZCtrl, Home); \
    AddCommand(ZCtrl, HomePropsSet); \
    AddCommand(ZCtrl, HomePropsGet); \
    AddCommand(ZCtrl, ActiveCtrlSet); \
    AddCommand(ZCtrl, CtrlListGet); \
    AddCommand(ZCtrl, Withdraw); \
    AddCommand(ZCtrl, WithdrawRateSet); \
    AddCommand(ZCtrl, WithdrawRateGet); \
    AddCommand(ZCtrl, LimitsEnabledSet); \
    AddCommand(ZCtrl, LimitsEnabledGet); \
    AddCommand(ZCtrl, LimitsSet); \
    AddCommand(ZCtrl, LimitsGet); \
    AddCommand(ZCtrl, StatusGet); \
    AddCommand(SafeTip, OnOffSet); \
    AddCommand(SafeTip, OnOffGet); \
    AddCommand(SafeTip, SignalGet); \
    AddCommand(SafeTip, PropsSet); \
    AddCommand(SafeTip, PropsGet); \
    AddCommand(AutoApproach, Open); \
    AddCommand(AutoApproach, OnOffSet); \
    AddCommand(AutoApproach, OnOffGet); \
    AddCommand(ZSpectr, Open); \
    AddCommand(ZSpectr, Start); \
    AddCommand(ZSpectr, Stop); \
    AddCommand(ZSpectr, StatusGet); \
    AddCommand(ZSpectr, ChsSet); \
    AddCommand(ZSpectr, ChsGet); \
    AddCommand(ZSpectr, PropsSet); \
    AddCommand(ZSpectr, PropsGet); \
    AddCommand(ZSpectr, AdvPropsSet); \
    AddCommand(ZSpectr, AdvPropsGet); \
    AddCommand(ZSpectr, RangeSet); \
    AddCommand(ZSpectr, RangeGet); \
    AddCommand(ZSpectr, TimingSet); \
    AddCommand(ZSpectr, TimingGet); \
    AddCommand(ZSpectr, RetractDelaySet); \
    AddCommand(ZSpectr, RetractDelayGet); \
    AddCommand(ZSpectr, RetractSet); \
    AddCommand(ZSpectr, RetractGet); \
    AddCommand(ZSpectr, Retract2ndSet); \
    AddCommand(ZSpectr, Retract2ndGet); \
    AddCommand(Piezo, TiltSet); \
    AddCommand(Piezo, TiltGet); \
    AddCommand(Piezo, RangeSet); \
    AddCommand(Piezo, RangeGet); \
    AddCommand(Piezo, SensSet); \
    AddCommand(Piezo, SensGet); \
    AddCommand(Piezo, DriftCompSet); \
    AddCommand(Piezo, DriftCompGet); \
    AddCommand(Piezo, CalibrGet); \
    AddCommand(Piezo, HVAInfoGet); \
    AddCommand(Piezo, HVAStatusLEDGet); \
    AddCommand(Scan, Action); \
    AddCommand(Scan, StatusGet); \
    AddCommand(Scan, WaitEndOfScan); \
    AddCommand(Scan, FrameSet); \
    AddCommand(Scan, FrameGet); \
    AddCommand(Scan, BufferSet); \
    AddCommand(Scan, BufferGet); \
    AddCommand(Scan, PropsSet); \
    AddCommand(Scan, PropsGet); \
    AddCommand(Scan, SpeedSet); \
    AddCommand(Scan, SpeedGet); \
    AddCommand(Scan, FrameDataGrab); \
    AddCommand(FolMe, XYPosSet); \
    AddCommand(FolMe, XYPosGet); \
    AddCommand(FolMe, SpeedSet); \
    AddCommand(FolMe, SpeedGet); \
    AddCommand(FolMe, OversamplSet); \
    AddCommand(FolMe, OversamplGet); \
    AddCommand(FolMe, Stop); \
    AddCommand(FolMe, PSOnOffGet); \
    AddCommand(FolMe, PSOnOffSet); \
    AddCommand(FolMe, PSExpGet); \
    AddCommand(FolMe, PSExpSet); \
    AddCommand(FolMe, PSPropsGet); \
    AddCommand(FolMe, PSPropsSet); \
    AddCommand(TipRec, BufferSizeSet); \
    AddCommand(TipRec, BufferSizeGet); \
    AddCommand(TipRec, BufferClear); \
    AddCommand(TipRec, DataGet); \
    AddCommand(TipRec, DataSave); \
    AddCommand(Pattern, ExpOpen); \
    AddCommand(Pattern, ExpStart); \
    AddCommand(Pattern, ExpPause); \
    AddCommand(Pattern, ExpStop); \
    AddCommand(Pattern, ExpStatusGet); \
    AddCommand(Pattern, GridSet); \
    AddCommand(Pattern, GridGet); \
    AddCommand(Pattern, LineSet); \
    AddCommand(Pattern, LineGet); \
    AddCommand(Pattern, CloudSet); \
    AddCommand(Pattern, CloudGet); \
    AddCommand(Pattern, PropsSet); \
    AddCommand(Pattern, PropsGet); \
    AddCommand(Marks, PointDraw); \
    AddCommand(Marks, PointsDraw); \
    AddCommand(Marks, LineDraw); \
    AddCommand(Marks, LinesDraw); \
    AddCommand(Marks, PointsErase); \
    AddCommand(Marks, LinesErase); \
    AddCommand(Marks, PointsVisibleSet); \
    AddCommand(Marks, LinesVisibleSet); \
    AddCommand(Marks, PointsGet); \
    AddCommand(Marks, LinesGet); \
    AddCommand(TipShaper, Start); \
    AddCommand(TipShaper, PropsSet); \
    AddCommand(TipShaper, PropsGet); \
    AddCommand(Motor, StartMove); \
    AddCommand(Motor, StartClosedLoop); \
    AddCommand(Motor, StopMove); \
    AddCommand(Motor, PosGet); \
    AddCommand(Motor, StepCounterGet); \
    AddCommand(Motor, FreqAmpGet); \
    AddCommand(Motor, FreqAmpSet); \
    AddCommand(GenSwp, AcqChsSet); \
    AddCommand(GenSwp, AcqChsGet); \
    AddCommand(GenSwp, SwpSignalSet); \
    AddCommand(GenSwp, SwpSignalGet); \
    AddCommand(GenSwp, LimitsSet); \
    AddCommand(GenSwp, LimitsGet); \
    AddCommand(GenSwp, PropsSet); \
    AddCommand(GenSwp, PropsGet); \
    AddCommand(GenSwp, Start); \
    AddCommand(GenSwp, Stop); \
    AddCommand(GenSwp, Open); \
    AddCommand(GenPICtrl, OnOffSet); \
    AddCommand(GenPICtrl, OnOffGet); \
    AddCommand(GenPICtrl, AOValSet); \
    AddCommand(GenPICtrl, AOValGet); \
    AddCommand(GenPICtrl, AOPropsSet); \
    AddCommand(GenPICtrl, AOPropsGet); \
    AddCommand(GenPICtrl, ModChSet); \
    AddCommand(GenPICtrl, ModChGet); \
    AddCommand(GenPICtrl, DemodChSet); \
    AddCommand(GenPICtrl, DemodChGet); \
    AddCommand(GenPICtrl, PropsSet); \
    AddCommand(GenPICtrl, PropsGet); \
    AddCommand(AtomTrack, CtrlSet); \
    AddCommand(AtomTrack, StatusGet); \
    AddCommand(AtomTrack, PropsSet); \
    AddCommand(AtomTrack, PropsGet); \
    AddCommand(AtomTrack, QuickCompStart); \
    AddCommand(AtomTrack, DriftComp); \
    AddCommand(LockIn, ModOnOffSet); \
    AddCommand(LockIn, ModOnOffGet); \
    AddCommand(LockIn, ModSignalSet); \
    AddCommand(LockIn, ModSignalGet); \
    AddCommand(LockIn, ModPhasRegSet); \
    AddCommand(LockIn, ModPhasRegGet); \
    AddCommand(LockIn, ModHarmonicSet); \
    AddCommand(LockIn, ModHarmonicGet); \
    AddCommand(LockIn, ModPhasSet); \
    AddCommand(LockIn, ModPhasGet); \
    AddCommand(LockIn, ModAmpSet); \
    AddCommand(LockIn, ModAmpGet); \
    AddCommand(LockIn, ModPhasFreqSet); \
    AddCommand(LockIn, ModPhasFreqGet); \
    AddCommand(LockIn, DemodSignalSet); \
    AddCommand(LockIn, DemodSignalGet); \
    AddCommand(LockIn, DemodHarmonicSet); \
    AddCommand(LockIn, DemodHarmonicGet); \
    AddCommand(LockIn, DemodHPFilterSet); \
    AddCommand(LockIn, DemodHPFilterGet); \
    AddCommand(LockIn, DemodLPFilterSet); \
    AddCommand(LockIn, DemodLPFilterGet); \
    AddCommand(LockIn, DemodPhasRegSet); \
    AddCommand(LockIn, DemodPhasRegGet); \
    AddCommand(LockIn, DemodPhasSet); \
    AddCommand(LockIn, DemodPhasGet); \
    AddCommand(LockIn, DemodSyncFilterSet); \
    AddCommand(LockIn, DemodSyncFilterGet); \
    AddCommand(LockIn, DemodRTSignalsSet); \
    AddCommand(LockIn, DemodRTSignalsGet); \
    AddCommand(LockInFreqSwp, Open); \
    AddCommand(LockInFreqSwp, Start); \
    AddCommand(LockInFreqSwp, SignalSet); \
    AddCommand(LockInFreqSwp, SignalGet); \
    AddCommand(LockInFreqSwp, LimitsSet); \
    AddCommand(LockInFreqSwp, LimitsGet); \
    AddCommand(LockInFreqSwp, PropsSet); \
    AddCommand(LockInFreqSwp, PropsGet); \
    AddCommand(PLL, InpCalibrSet); \
    AddCommand(PLL, InpCalibrGet); \
    AddCommand(PLL, InpRangeSet); \
    AddCommand(PLL, InpRangeGet); \
    AddCommand(PLL, InpPropsSet); \
    AddCommand(PLL, InpPropsGet); \
    AddCommand(PLL, AddOnOffSet); \
    AddCommand(PLL, AddOnOffGet); \
    AddCommand(PLL, OutOnOffSet); \
    AddCommand(PLL, OutOnOffGet); \
    AddCommand(PLL, ExcRangeSet); \
    AddCommand(PLL, ExcRangeGet); \
    AddCommand(PLL, ExcitationSet); \
    AddCommand(PLL, ExcitationGet); \
    AddCommand(PLL, AmpCtrlSetpntSet); \
    AddCommand(PLL, AmpCtrlSetpntGet); \
    AddCommand(PLL, AmpCtrlOnOffSet); \
    AddCommand(PLL, AmpCtrlOnOffGet); \
    AddCommand(PLL, AmpCtrlGainSet); \
    AddCommand(PLL, AmpCtrlGainGet); \
    AddCommand(PLL, AmpCtrlBandwidthSet); \
    AddCommand(PLL, AmpCtrlBandwidthGet); \
    AddCommand(PLL, PhasCtrlOnOffSet); \
    AddCommand(PLL, PhasCtrlOnOffGet); \
    AddCommand(PLL, PhasCtrlGainSet); \
    AddCommand(PLL, PhasCtrlGainGet); \
    AddCommand(PLL, PhasCtrlBandwidthSet); \
    AddCommand(PLL, PhasCtrlBandwidthGet); \
    AddCommand(PLL, FreqRangeSet); \
    AddCommand(PLL, FreqRangeGet); \
    AddCommand(PLL, CenterFreqSet); \
    AddCommand(PLL, CenterFreqGet); \
    AddCommand(PLL, FreqShiftSet); \
    AddCommand(PLL, FreqShiftGet); \
    AddCommand(PLL, FreqShiftAutoCenter); \
    AddCommand(PLL, FreqExcOverwriteSet); \
    AddCommand(PLL, FreqExcOverwriteGet); \
    AddCommand(PLL, DemodInputSet); \
    AddCommand(PLL, DemodInputGet); \
    AddCommand(PLL, DemodHarmonicSet); \
    AddCommand(PLL, DemodHarmonicGet); \
    AddCommand(PLL, DemodPhasRefSet); \
    AddCommand(PLL, DemodPhasRefGet); \
    AddCommand(PLL, DemodFilterSet); \
    AddCommand(PLL, DemodFilterGet); \
    AddCommand(PLLQCtrl, AccessRequest); \
    AddCommand(PLLQCtrl, AccessGet); \
    AddCommand(PLLQCtrl, OnOffSet); \
    AddCommand(PLLQCtrl, OnOffGet); \
    AddCommand(PLLQCtrl, QGainSet); \
    AddCommand(PLLQCtrl, QGainGet); \
    AddCommand(PLLQCtrl, PhaseSet); \
    AddCommand(PLLQCtrl, PhaseGet); \
    AddCommand(PLLFreqSwp, Open); \
    AddCommand(PLLFreqSwp, ParamsSet); \
    AddCommand(PLLFreqSwp, ParamsGet); \
    AddCommand(PLLFreqSwp, Start); \
    AddCommand(PLLFreqSwp, Stop); \
    AddCommand(PLLPhasSwp, Start); \
    AddCommand(PLLPhasSwp, Stop); \
    AddCommand(PLLSignalAnlzr, Open); \
    AddCommand(PLLSignalAnlzr, ChSet); \
    AddCommand(PLLSignalAnlzr, ChGet); \
    AddCommand(PLLSignalAnlzr, TimebaseSet); \
    AddCommand(PLLSignalAnlzr, TimebaseGet); \
    AddCommand(PLLSignalAnlzr, TrigAuto); \
    AddCommand(PLLSignalAnlzr, TrigRearm); \
    AddCommand(PLLSignalAnlzr, TrigSet); \
    AddCommand(PLLSignalAnlzr, TrigGet); \
    AddCommand(PLLSignalAnlzr, OsciDataGet); \
    AddCommand(PLLSignalAnlzr, FFTPropsSet); \
    AddCommand(PLLSignalAnlzr, FFTPropsGet); \
    AddCommand(PLLSignalAnlzr, FFTAvgRestart); \
    AddCommand(PLLSignalAnlzr, FFTDataGet); \
    AddCommand(PLLZoomFFT, Open); \
    AddCommand(PLLZoomFFT, ChSet); \
    AddCommand(PLLZoomFFT, ChGet); \
    AddCommand(PLLZoomFFT, AvgRestart); \
    AddCommand(PLLZoomFFT, PropsSet); \
    AddCommand(PLLZoomFFT, PropsGet); \
    AddCommand(PLLZoomFFT, DataGet); \
    AddCommand(OCSync, AnglesSet); \
    AddCommand(OCSync, AnglesGet); \
    AddCommand(OCSync, LinkAnglesSet); \
    AddCommand(OCSync, LinkAnglesGet); \
    AddCommand(Script, Load); \
    AddCommand(Script, Save); \
    AddCommand(Script, Deploy); \
    AddCommand(Script, Undeploy); \
    AddCommand(Script, Run); \
    AddCommand(Script, Stop); \
    AddCommand(Script, ChsGet); \
    AddCommand(Script, ChsSet); \
    AddCommand(Script, DataGet); \
    AddCommand(Script, Autosave); \
    AddCommand(Interf, CtrlOnOffSet); \
    AddCommand(Interf, CtrlOnOffGet); \
    AddCommand(Interf, CtrlPropsSet); \
    AddCommand(Interf, CtrlPropsGet); \
    AddCommand(Interf, WPiezoSet); \
    AddCommand(Interf, WPiezoGet); \
    AddCommand(Interf, ValGet); \
    AddCommand(Interf, CtrlCalibrOpen); \
    AddCommand(Interf, CtrlReset); \
    AddCommand(Interf, CtrlNullDefl); \
    AddCommand(Laser, OnOffSet); \
    AddCommand(Laser, OnOffGet); \
    AddCommand(Laser, PropsSet); \
    AddCommand(Laser, PropsGet); \
    AddCommand(Laser, PowerGet); \
    AddCommand(BeamDefl, HorConfigSet); \
    AddCommand(BeamDefl, HorConfigGet); \
    AddCommand(BeamDefl, VerConfigSet); \
    AddCommand(BeamDefl, VerConfigGet); \
    AddCommand(BeamDefl, IntConfigSet); \
    AddCommand(BeamDefl, IntConfigGet); \
    AddCommand(BeamDefl, AutoOffset); \
    AddCommand(Signals, NamesGet); \
    AddCommand(Signals, InSlotSet); \
    AddCommand(Signals, InSlotsGet); \
    AddCommand(Signals, CalibrGet); \
    AddCommand(Signals, RangeGet); \
    AddCommand(Signals, ValGet); \
    AddCommand(Signals, ValsGet); \
    AddCommand(Signals, MeasNamesGet); \
    AddCommand(Signals, AddRTGet); \
    AddCommand(Signals, AddRTSet); \
    AddCommand(UserIn, CalibrSet); \
    AddCommand(UserOut, ModeSet); \
    AddCommand(UserOut, ModeGet); \
    AddCommand(UserOut, MonitorChSet); \
    AddCommand(UserOut, MonitorChGet); \
    AddCommand(UserOut, ValSet); \
    AddCommand(UserOut, CalibrSet); \
    AddCommand(UserOut, CalcSignalNameSet); \
    AddCommand(UserOut, CalcSignalNameGet); \
    AddCommand(UserOut, CalcSignalConfigSet); \
    AddCommand(UserOut, CalcSignalConfigGet); \
    AddCommand(UserOut, LimitsSet); \
    AddCommand(UserOut, LimitsGet); \
    AddCommand(DigLines, PropsSet); \
    AddCommand(DigLines, OutStatusSet); \
    AddCommand(DigLines, TTLValGet); \
    AddCommand(DigLines, Pulse); \
    AddCommand(DataLog, Open); \
    AddCommand(DataLog, Start); \
    AddCommand(DataLog, Stop); \
    AddCommand(DataLog, StatusGet); \
    AddCommand(DataLog, ChsSet); \
    AddCommand(DataLog, ChsGet); \
    AddCommand(DataLog, PropsSet); \
    AddCommand(DataLog, PropsGet); \
    AddCommand(TCPLog, Start); \
    AddCommand(TCPLog, Stop); \
    AddCommand(TCPLog, ChsSet); \
    AddCommand(TCPLog, OversamplSet); \
    AddCommand(TCPLog, StatusGet); \
    AddCommand(OsciHR, ChSet); \
    AddCommand(OsciHR, ChGet); \
    AddCommand(OsciHR, OversamplSet); \
    AddCommand(OsciHR, OversamplGet); \
    AddCommand(OsciHR, CalibrModeSet); \
    AddCommand(OsciHR, CalibrModeGet); \
    AddCommand(OsciHR, SamplesSet); \
    AddCommand(OsciHR, SamplesGet); \
    AddCommand(OsciHR, PreTrigSet); \
    AddCommand(OsciHR, PreTrigGet); \
    AddCommand(OsciHR, Run); \
    AddCommand(OsciHR, OsciDataGet); \
    AddCommand(OsciHR, TrigModeSet); \
    AddCommand(OsciHR, TrigModeGet); \
    AddCommand(OsciHR, TrigLevChSet); \
    AddCommand(OsciHR, TrigLevChGet); \
    AddCommand(OsciHR, TrigLevValSet); \
    AddCommand(OsciHR, TrigLevValGet); \
    AddCommand(OsciHR, TrigLevHystSet); \
    AddCommand(OsciHR, TrigLevHystGet); \
    AddCommand(OsciHR, TrigLevSlopeSet); \
    AddCommand(OsciHR, TrigLevSlopeGet); \
    AddCommand(OsciHR, TrigDigChSet); \
    AddCommand(OsciHR, TrigDigChGet); \
    AddCommand(OsciHR, TrigArmModeSet); \
    AddCommand(OsciHR, TrigArmModeGet); \
    AddCommand(OsciHR, TrigDigSlopeSet); \
    AddCommand(OsciHR, TrigDigSlopeGet); \
    AddCommand(OsciHR, TrigRearm); \
    AddCommand(OsciHR, PSDShow); \
    AddCommand(OsciHR, PSDWeightSet); \
    AddCommand(OsciHR, PSDWeightGet); \
    AddCommand(OsciHR, PSDWindowSet); \
    AddCommand(OsciHR, PSDWindowGet); \
    AddCommand(OsciHR, PSDAvrgTypeSet); \
    AddCommand(OsciHR, PSDAvrgTypeGet); \
    AddCommand(OsciHR, PSDAvrgCountSet); \
    AddCommand(OsciHR, PSDAvrgCountGet); \
    AddCommand(OsciHR, PSDAvrgRestart); \
    AddCommand(OsciHR, PSDDataGet); \
    AddCommand(Osci1T, ChSet); \
    AddCommand(Osci1T, ChGet); \
    AddCommand(Osci1T, TimebaseSet); \
    AddCommand(Osci1T, TimebaseGet); \
    AddCommand(Osci1T, TrigSet); \
    AddCommand(Osci1T, TrigGet); \
    AddCommand(Osci1T, Run); \
    AddCommand(Osci1T, DataGet); \
    AddCommand(Osci2T, ChsSet); \
    AddCommand(Osci2T, ChsGet); \
    AddCommand(Osci2T, TimebaseSet); \
    AddCommand(Osci2T, TimebaseGet); \
    AddCommand(Osci2T, OversamplSet); \
    AddCommand(Osci2T, OversamplGet); \
    AddCommand(Osci2T, TrigSet); \
    AddCommand(Osci2T, TrigGet); \
    AddCommand(Osci2T, Run); \
    AddCommand(Osci2T, DataGet); \
    AddCommand(SignalChart, Open); \
    AddCommand(SignalChart, ChsSet); \
    AddCommand(SignalChart, ChsGet); \
    AddCommand(SpectrumAnlzr, ChSet); \
    AddCommand(SpectrumAnlzr, ChGet); \
    AddCommand(SpectrumAnlzr, FreqRangeSet); \
    AddCommand(SpectrumAnlzr, FreqRangeGet); \
    AddCommand(SpectrumAnlzr, FreqResSet); \
    AddCommand(SpectrumAnlzr, FreqResGet); \
    AddCommand(SpectrumAnlzr, FFTWindowSet); \
    AddCommand(SpectrumAnlzr, FFTWindowGet); \
    AddCommand(SpectrumAnlzr, AveragSet); \
    AddCommand(SpectrumAnlzr, AveragGet); \
    AddCommand(SpectrumAnlzr, ACCouplingSet); \
    AddCommand(SpectrumAnlzr, ACCouplingGet); \
    AddCommand(SpectrumAnlzr, CursorPosSet); \
    AddCommand(SpectrumAnlzr, CursorPosGet); \
    AddCommand(SpectrumAnlzr, BandRMSGet); \
    AddCommand(SpectrumAnlzr, DCGet); \
    AddCommand(SpectrumAnlzr, Run); \
    AddCommand(SpectrumAnlzr, DataGet); \
    AddCommand(FunGen1Ch, Start); \
    AddCommand(FunGen1Ch, Stop); \
    AddCommand(FunGen1Ch, StatusGet); \
    AddCommand(FunGen1Ch, PropsSet); \
    AddCommand(FunGen1Ch, PropsGet); \
    AddCommand(FunGen1Ch, IdleSet); \
    AddCommand(FunGen1Ch, IdleGet); \
    AddCommand(FunGen2Ch, Start); \
    AddCommand(FunGen2Ch, Stop); \
    AddCommand(FunGen2Ch, StatusGet); \
    AddCommand(FunGen2Ch, IdleSet); \
    AddCommand(FunGen2Ch, IdleGet); \
    AddCommand(FunGen2Ch, OnOffSet); \
    AddCommand(FunGen2Ch, OnOffGet); \
    AddCommand(FunGen2Ch, SignalSet); \
    AddCommand(FunGen2Ch, SignalGet); \
    AddCommand(FunGen2Ch, PropsSet); \
    AddCommand(FunGen2Ch, PropsGet); \
    AddCommand(FunGen2Ch, WaveformSet); \
    AddCommand(FunGen2Ch, WaveformGet); \
    AddCommand(Util, SessionPathGet); \
    AddCommand(Util, SettingsLoad); \
    AddCommand(Util, SettingsSave); \
    AddCommand(Util, LayoutLoad); \
    AddCommand(Util, LayoutSave); \
    AddCommand(Util, Lock); \
    AddCommand(Util, UnLock); \
    AddCommand(Util, RTFreqSet); \
    AddCommand(Util, RTFreqGet); \
    AddCommand(Util, AcqPeriodSet); \
    AddCommand(Util, AcqPeriodGet); \
    AddCommand(Util, RTOversamplSet); \
    AddCommand(Util, RTOversamplGet); \
    AddCommand(Util, Quit);    

#define AddBiasFunctions \
    AddFunction(Bias, Set, nano_float32); \
    AddFunction(Bias, Get); \
    AddFunction(Bias, RangeSet, nano_unsigned_int16); \
    AddFunction(Bias, RangeGet); \
    AddFunction(Bias, CalibrSet, nano_float32, nano_float32); \
    AddFunction(Bias, CalibrGet); \
    AddFunction(Bias, Pulse, nano_unsigned_int32, nano_float32, nano_float32, nano_unsigned_int16, nano_unsigned_int16);

#define AddBiasSwpFunctions \
    AddFunction(BiasSwp, Open); \
    AddFunction(BiasSwp, Start, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32, nano_int, nano_string, nano_unsigned_int32); \
    AddFunction(BiasSwp, PropsSet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(BiasSwp, LimitsSet, nano_float32, nano_float32);

#define AddBiasSpectrFunctions \
    AddFunction(BiasSpectr, Open); \
    AddFunction(BiasSpectr, Start, nano_unsigned_int32, nano_int, nano_string); \
    AddFunction(BiasSpectr, Stop); \
    AddFunction(BiasSpectr, StatusGet); \
    AddFunction(BiasSpectr, ChsSet, nano_int, nano_1D_array_int); \
    AddFunction(BiasSpectr, ChsGet); \
    AddFunction(BiasSpectr, PropsSet, nano_unsigned_int16, nano_int, nano_unsigned_int16, nano_int, nano_float32, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(BiasSpectr, PropsGet); \
    AddFunction(BiasSpectr, AdvPropsSet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(BiasSpectr, AdvPropsGet); \
    AddFunction(BiasSpectr, LimitsSet, nano_float32, nano_float32); \
    AddFunction(BiasSpectr, LimitsGet); \
    AddFunction(BiasSpectr, TimingSet, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddFunction(BiasSpectr, TimingGet); \
    AddFunction(BiasSpectr, TTLSyncSet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16, nano_float32, nano_float32); \
    AddFunction(BiasSpectr, TTLSyncGet); \
    AddFunction(BiasSpectr, AltZCtrlSet, nano_unsigned_int16, nano_float32, nano_float32); \
    AddFunction(BiasSpectr, AltZCtrlGet); \
    AddFunction(BiasSpectr, MLSLockinPerSegSet, nano_unsigned_int32); \
    AddFunction(BiasSpectr, MLSLockinPerSegGet); \
    AddFunction(BiasSpectr, MLSModeSet, nano_int, nano_string); \
    AddFunction(BiasSpectr, MLSModeGet); \
    AddFunction(BiasSpectr, MLSValsSet, nano_int, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_int, nano_1D_array_unsigned_int32); \
    AddFunction(BiasSpectr, MLSValsGet);

#define AddKelvinCtrlFunctions \
    AddFunction(KelvinCtrl, CtrlOnOffSet, nano_unsigned_int32); \
    AddFunction(KelvinCtrl, CtrlOnOffGet); \
    AddFunction(KelvinCtrl, SetpntSet, nano_float32); \
    AddFunction(KelvinCtrl, SetpntGet); \
    AddFunction(KelvinCtrl, GainSet, nano_float32, nano_float32, nano_unsigned_int16); \
    AddFunction(KelvinCtrl, GainGet); \
    AddFunction(KelvinCtrl, ModParamsSet, nano_float32, nano_float32, nano_float32); \
    AddFunction(KelvinCtrl, ModParamsGet); \
    AddFunction(KelvinCtrl, ModOnOffSet, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(KelvinCtrl, ModOnOffGet); \
    AddFunction(KelvinCtrl, CtrlSignalSet, nano_int); \
    AddFunction(KelvinCtrl, CtrlSignalGet); \
    AddFunction(KelvinCtrl, AmpGet); \
    AddFunction(KelvinCtrl, BiasLimitsSet, nano_float32, nano_float32); \
    AddFunction(KelvinCtrl, BiasLimitsGet);

#define AddCPDCompFunctions \
    AddFunction(CPDComp, Open); \
    AddFunction(CPDComp, Close); \
    AddFunction(CPDComp, ParamsSet, nano_float32, nano_float32, nano_int); \
    AddFunction(CPDComp, ParamsGet); \
    AddFunction(CPDComp, DataGet);

#define AddCurrentFunctions \
    AddFunction(Current, Get); \
    AddFunction(Current, Get100); \
    AddFunction(Current, BEEMGet); \
    AddFunction(Current, GainSet, nano_unsigned_int16); \
    AddFunction(Current, GainsGet); \
    AddFunction(Current, CalibrSet, nano_float64, nano_float64); \
    AddFunction(Current, CalibrGet);

#define AddZCtrlFunctions \
    AddFunction(ZCtrl, ZPosSet, nano_float32); \
    AddFunction(ZCtrl, ZPosGet); \
    AddFunction(ZCtrl, OnOffSet, nano_unsigned_int32); \
    AddFunction(ZCtrl, OnOffGet); \
    AddFunction(ZCtrl, SetpntSet, nano_float32); \
    AddFunction(ZCtrl, SetpntGet); \
    AddFunction(ZCtrl, GainSet, nano_float32, nano_float32, nano_float32); \
    AddFunction(ZCtrl, GainGet); \
    AddFunction(ZCtrl, SwitchOffDelaySet, nano_float32); \
    AddFunction(ZCtrl, SwitchOffDelayGet); \
    AddFunction(ZCtrl, TipLiftSet, nano_float32); \
    AddFunction(ZCtrl, TipLiftGet); \
    AddFunction(ZCtrl, Home); \
    AddFunction(ZCtrl, HomePropsSet, nano_unsigned_int16, nano_float32); \
    AddFunction(ZCtrl, HomePropsGet); \
    AddFunction(ZCtrl, ActiveCtrlSet, nano_int); \
    AddFunction(ZCtrl, CtrlListGet); \
    AddFunction(ZCtrl, Withdraw, nano_unsigned_int32, nano_int); \
    AddFunction(ZCtrl, WithdrawRateSet, nano_float32); \
    AddFunction(ZCtrl, WithdrawRateGet); \
    AddFunction(ZCtrl, LimitsEnabledSet, nano_unsigned_int32); \
    AddFunction(ZCtrl, LimitsEnabledGet); \
    AddFunction(ZCtrl, LimitsSet, nano_float32, nano_float32); \
    AddFunction(ZCtrl, LimitsGet); \
    AddFunction(ZCtrl, StatusGet);

#define AddSafeTipFunctions \
    AddFunction(SafeTip, OnOffSet, nano_unsigned_int16); \
    AddFunction(SafeTip, OnOffGet); \
    AddFunction(SafeTip, SignalGet); \
    AddFunction(SafeTip, PropsSet, nano_unsigned_int16, nano_unsigned_int16, nano_float32); \
    AddFunction(SafeTip, PropsGet);

#define AddAutoApproachFunctions \
    AddFunction(AutoApproach, Open); \
    AddFunction(AutoApproach, OnOffSet, nano_unsigned_int16); \
    AddFunction(AutoApproach, OnOffGet);

#define AddZSpectrFunctions \
    AddFunction(ZSpectr, Open); \
    AddFunction(ZSpectr, Start, nano_unsigned_int32, nano_int, nano_string); \
    AddFunction(ZSpectr, Stop); \
    AddFunction(ZSpectr, StatusGet); \
    AddFunction(ZSpectr, ChsSet, nano_int, nano_1D_array_int); \
    AddFunction(ZSpectr, ChsGet); \
    AddFunction(ZSpectr, PropsSet, nano_unsigned_int16, nano_int, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(ZSpectr, PropsGet); \
    AddFunction(ZSpectr, AdvPropsSet, nano_float32, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(ZSpectr, AdvPropsGet); \
    AddFunction(ZSpectr, RangeSet, nano_float32, nano_float32); \
    AddFunction(ZSpectr, RangeGet); \
    AddFunction(ZSpectr, TimingSet, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddFunction(ZSpectr, TimingGet); \
    AddFunction(ZSpectr, RetractDelaySet, nano_float32); \
    AddFunction(ZSpectr, RetractDelayGet); \
    AddFunction(ZSpectr, RetractSet, nano_unsigned_int16, nano_float32, nano_int, nano_unsigned_int16); \
    AddFunction(ZSpectr, RetractGet); \
    AddFunction(ZSpectr, Retract2ndSet, nano_int, nano_float32, nano_int, nano_unsigned_int16); \
    AddFunction(ZSpectr, Retract2ndGet);

#define AddPiezoFunctions \
    AddFunction(Piezo, TiltSet, nano_float32, nano_float32); \
    AddFunction(Piezo, TiltGet); \
    AddFunction(Piezo, RangeSet, nano_float32, nano_float32, nano_float32); \
    AddFunction(Piezo, RangeGet); \
    AddFunction(Piezo, SensSet, nano_float32, nano_float32, nano_float32); \
    AddFunction(Piezo, SensGet); \
    AddFunction(Piezo, DriftCompSet, nano_unsigned_int32, nano_float32, nano_float32, nano_float32); \
    AddFunction(Piezo, DriftCompGet); \
    AddFunction(Piezo, CalibrGet); \
    AddFunction(Piezo, HVAInfoGet); \
    AddFunction(Piezo, HVAStatusLEDGet);

#define AddScanFunctions \
    AddFunction(Scan, Action, nano_unsigned_int16, nano_unsigned_int32); \
    AddFunction(Scan, StatusGet); \
    AddFunction(Scan, WaitEndOfScan, nano_int); \
    AddFunction(Scan, FrameSet, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddFunction(Scan, FrameGet); \
    AddFunction(Scan, BufferSet, nano_int, nano_1D_array_int, nano_int, nano_int); \
    AddFunction(Scan, BufferGet); \
    AddFunction(Scan, PropsSet, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32, nano_int, nano_string, nano_int, nano_string); \
    AddFunction(Scan, PropsGet); \
    AddFunction(Scan, SpeedSet, nano_float32, nano_float32, nano_float32, nano_float32, nano_unsigned_int16, nano_float32); \
    AddFunction(Scan, SpeedGet); \
    AddFunction(Scan, FrameDataGrab, nano_unsigned_int32, nano_unsigned_int32);

#define AddFolMeFunctions \
    AddFunction(FolMe, XYPosSet, nano_float64, nano_float64, nano_unsigned_int32); \
    AddFunction(FolMe, XYPosGet, nano_unsigned_int32); \
    AddFunction(FolMe, SpeedSet, nano_float32, nano_unsigned_int32); \
    AddFunction(FolMe, SpeedGet); \
    AddFunction(FolMe, OversamplSet, nano_int); \
    AddFunction(FolMe, OversamplGet); \
    AddFunction(FolMe, Stop); \
    AddFunction(FolMe, PSOnOffGet); \
    AddFunction(FolMe, PSOnOffSet, nano_unsigned_int32); \
    AddFunction(FolMe, PSExpGet); \
    AddFunction(FolMe, PSExpSet, nano_unsigned_int16); \
    AddFunction(FolMe, PSPropsGet); \
    AddFunction(FolMe, PSPropsSet, nano_unsigned_int32, nano_unsigned_int32, nano_int, nano_string, nano_int, nano_string, nano_float32);

#define AddTipRecFunctions \
    AddFunction(TipRec, BufferSizeSet, nano_int); \
    AddFunction(TipRec, BufferSizeGet); \
    AddFunction(TipRec, BufferClear); \
    AddFunction(TipRec, DataGet); \
    AddFunction(TipRec, DataSave, nano_unsigned_int32, nano_int, nano_string);

#define AddPatternFunctions \
    AddFunction(Pattern, ExpOpen); \
    AddFunction(Pattern, ExpStart, nano_unsigned_int16); \
    AddFunction(Pattern, ExpPause, nano_unsigned_int32); \
    AddFunction(Pattern, ExpStop); \
    AddFunction(Pattern, ExpStatusGet); \
    AddFunction(Pattern, GridSet, nano_unsigned_int32, nano_int, nano_int, nano_unsigned_int32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddFunction(Pattern, GridGet); \
    AddFunction(Pattern, LineSet, nano_unsigned_int32, nano_int, nano_unsigned_int32, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddFunction(Pattern, LineGet); \
    AddFunction(Pattern, CloudSet, nano_unsigned_int32, nano_int, nano_1D_array_float32, nano_1D_array_float32); \
    AddFunction(Pattern, CloudGet); \
    AddFunction(Pattern, PropsSet, nano_int, nano_string, nano_int, nano_string, nano_int, nano_string, nano_float32, nano_unsigned_int32); \
    AddFunction(Pattern, PropsGet);

#define AddMarksFunctions \
    AddFunction(Marks, PointDraw, nano_float32, nano_float32, nano_int, nano_string, nano_unsigned_int32); \
    AddFunction(Marks, PointsDraw, nano_int, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_string, nano_1D_array_unsigned_int32); \
    AddFunction(Marks, LineDraw, nano_float32, nano_float32, nano_float32, nano_float32, nano_unsigned_int32); \
    AddFunction(Marks, LinesDraw, nano_int, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_unsigned_int32); \
    AddFunction(Marks, PointsErase, nano_int); \
    AddFunction(Marks, LinesErase, nano_int); \
    AddFunction(Marks, PointsVisibleSet, nano_int, nano_unsigned_int16); \
    AddFunction(Marks, LinesVisibleSet, nano_int, nano_unsigned_int16); \
    AddFunction(Marks, PointsGet); \
    AddFunction(Marks, LinesGet);

#define AddTipShaperFunctions \
    AddFunction(TipShaper, Start, nano_unsigned_int32, nano_int); \
    AddFunction(TipShaper, PropsSet, nano_float32, nano_unsigned_int32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_unsigned_int32); \
    AddFunction(TipShaper, PropsGet);

#define AddMotorFunctions \
    AddFunction(Motor, StartMove, nano_unsigned_int32, nano_unsigned_int16, nano_unsigned_int32, nano_unsigned_int32); \
    AddFunction(Motor, StartClosedLoop, nano_unsigned_int32, nano_float64, nano_float64, nano_float64, nano_unsigned_int32); \
    AddFunction(Motor, StopMove); \
    AddFunction(Motor, PosGet); \
    AddFunction(Motor, StepCounterGet, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32); \
    AddFunction(Motor, FreqAmpGet); \
    AddFunction(Motor, FreqAmpSet, nano_float32, nano_float32, nano_unsigned_int16);

#define AddGenSwpFunctions \
    AddFunction(GenSwp, AcqChsSet, nano_int, nano_1D_array_int); \
    AddFunction(GenSwp, AcqChsGet); \
    AddFunction(GenSwp, SwpSignalSet, nano_int, nano_string); \
    AddFunction(GenSwp, SwpSignalGet); \
    AddFunction(GenSwp, LimitsSet, nano_float32, nano_float32); \
    AddFunction(GenSwp, LimitsGet); \
    AddFunction(GenSwp, PropsSet, nano_float32, nano_float32, nano_int, nano_unsigned_int16, nano_int, nano_int, nano_float32); \
    AddFunction(GenSwp, PropsGet); \
    AddFunction(GenSwp, Start, nano_unsigned_int32, nano_unsigned_int32, nano_int, nano_string, nano_unsigned_int32); \
    AddFunction(GenSwp, Stop); \
    AddFunction(GenSwp, Open);

#define AddGenPICtrlFunctions \
    AddFunction(GenPICtrl, OnOffSet, nano_unsigned_int32); \
    AddFunction(GenPICtrl, OnOffGet); \
    AddFunction(GenPICtrl, AOValSet, nano_float32); \
    AddFunction(GenPICtrl, AOValGet); \
    AddFunction(GenPICtrl, AOPropsSet, nano_int, nano_string, nano_int, nano_string, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddFunction(GenPICtrl, AOPropsGet); \
    AddFunction(GenPICtrl, ModChSet, nano_int); \
    AddFunction(GenPICtrl, ModChGet); \
    AddFunction(GenPICtrl, DemodChSet, nano_int, nano_unsigned_int16); \
    AddFunction(GenPICtrl, DemodChGet); \
    AddFunction(GenPICtrl, PropsSet, nano_float32, nano_float32, nano_float32, nano_unsigned_int16); \
    AddFunction(GenPICtrl, PropsGet);

#define AddAtomTrackFunctions \
    AddFunction(AtomTrack, CtrlSet, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(AtomTrack, StatusGet, nano_unsigned_int16); \
    AddFunction(AtomTrack, PropsSet, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddFunction(AtomTrack, PropsGet); \
    AddFunction(AtomTrack, QuickCompStart, nano_unsigned_int16); \
    AddFunction(AtomTrack, DriftComp);

#define AddLockInFunctions \
    AddFunction(LockIn, ModOnOffSet, nano_int, nano_unsigned_int32); \
    AddFunction(LockIn, ModOnOffGet, nano_int); \
    AddFunction(LockIn, ModSignalSet, nano_int, nano_int); \
    AddFunction(LockIn, ModSignalGet, nano_int); \
    AddFunction(LockIn, ModPhasRegSet, nano_int, nano_int); \
    AddFunction(LockIn, ModPhasRegGet, nano_int); \
    AddFunction(LockIn, ModHarmonicSet, nano_int, nano_int); \
    AddFunction(LockIn, ModHarmonicGet, nano_int); \
    AddFunction(LockIn, ModPhasSet, nano_int, nano_float32); \
    AddFunction(LockIn, ModPhasGet, nano_int); \
    AddFunction(LockIn, ModAmpSet, nano_int, nano_float32); \
    AddFunction(LockIn, ModAmpGet, nano_int); \
    AddFunction(LockIn, ModPhasFreqSet, nano_int, nano_float32); \
    AddFunction(LockIn, ModPhasFreqGet, nano_int); \
    AddFunction(LockIn, DemodSignalSet, nano_int, nano_int); \
    AddFunction(LockIn, DemodSignalGet, nano_int); \
    AddFunction(LockIn, DemodHarmonicSet, nano_int, nano_int); \
    AddFunction(LockIn, DemodHarmonicGet, nano_int); \
    AddFunction(LockIn, DemodHPFilterSet, nano_int, nano_int, nano_float32); \
    AddFunction(LockIn, DemodHPFilterGet, nano_int); \
    AddFunction(LockIn, DemodLPFilterSet, nano_int, nano_int, nano_float32); \
    AddFunction(LockIn, DemodLPFilterGet, nano_int); \
    AddFunction(LockIn, DemodPhasRegSet, nano_int, nano_int); \
    AddFunction(LockIn, DemodPhasRegGet, nano_int); \
    AddFunction(LockIn, DemodPhasSet, nano_int, nano_float32); \
    AddFunction(LockIn, DemodPhasGet, nano_int); \
    AddFunction(LockIn, DemodSyncFilterSet, nano_int, nano_unsigned_int32); \
    AddFunction(LockIn, DemodSyncFilterGet, nano_int); \
    AddFunction(LockIn, DemodRTSignalsSet, nano_int, nano_unsigned_int32); \
    AddFunction(LockIn, DemodRTSignalsGet, nano_int);

#define AddLockInFreqSwpFunctions \
    AddFunction(LockInFreqSwp, Open); \
    AddFunction(LockInFreqSwp, Start, nano_unsigned_int32, nano_unsigned_int32); \
    AddFunction(LockInFreqSwp, SignalSet, nano_int); \
    AddFunction(LockInFreqSwp, SignalGet); \
    AddFunction(LockInFreqSwp, LimitsSet, nano_float32, nano_float32); \
    AddFunction(LockInFreqSwp, LimitsGet); \
    AddFunction(LockInFreqSwp, PropsSet, nano_unsigned_int16, nano_unsigned_int16, nano_float32, nano_unsigned_int16, nano_float32, nano_unsigned_int32, nano_unsigned_int32, nano_int, nano_string); \
    AddFunction(LockInFreqSwp, PropsGet);

#define AddPLLFunctions \
    AddFunction(PLL, InpCalibrSet, nano_int, nano_float32); \
    AddFunction(PLL, InpCalibrGet, nano_int); \
    AddFunction(PLL, InpRangeSet, nano_int, nano_float32); \
    AddFunction(PLL, InpRangeGet, nano_int); \
    AddFunction(PLL, InpPropsSet, nano_int, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(PLL, InpPropsGet, nano_int); \
    AddFunction(PLL, AddOnOffSet, nano_int, nano_unsigned_int32); \
    AddFunction(PLL, AddOnOffGet, nano_int); \
    AddFunction(PLL, OutOnOffSet, nano_int, nano_unsigned_int32); \
    AddFunction(PLL, OutOnOffGet, nano_int); \
    AddFunction(PLL, ExcRangeSet, nano_int, nano_unsigned_int16); \
    AddFunction(PLL, ExcRangeGet, nano_int); \
    AddFunction(PLL, ExcitationSet, nano_int, nano_float32); \
    AddFunction(PLL, ExcitationGet, nano_int); \
    AddFunction(PLL, AmpCtrlSetpntSet, nano_int, nano_float32); \
    AddFunction(PLL, AmpCtrlSetpntGet, nano_int); \
    AddFunction(PLL, AmpCtrlOnOffSet, nano_int, nano_unsigned_int32); \
    AddFunction(PLL, AmpCtrlOnOffGet, nano_int); \
    AddFunction(PLL, AmpCtrlGainSet, nano_int, nano_float32, nano_float32); \
    AddFunction(PLL, AmpCtrlGainGet, nano_int); \
    AddFunction(PLL, AmpCtrlBandwidthSet, nano_int, nano_float32); \
    AddFunction(PLL, AmpCtrlBandwidthGet, nano_int); \
    AddFunction(PLL, PhasCtrlOnOffSet, nano_int, nano_unsigned_int32); \
    AddFunction(PLL, PhasCtrlOnOffGet, nano_int); \
    AddFunction(PLL, PhasCtrlGainSet, nano_int, nano_float32, nano_float32); \
    AddFunction(PLL, PhasCtrlGainGet, nano_int); \
    AddFunction(PLL, PhasCtrlBandwidthSet, nano_int, nano_float32); \
    AddFunction(PLL, PhasCtrlBandwidthGet, nano_int); \
    AddFunction(PLL, FreqRangeSet, nano_int, nano_float32); \
    AddFunction(PLL, FreqRangeGet, nano_int); \
    AddFunction(PLL, CenterFreqSet, nano_int, nano_float64); \
    AddFunction(PLL, CenterFreqGet, nano_int); \
    AddFunction(PLL, FreqShiftSet, nano_int, nano_float32); \
    AddFunction(PLL, FreqShiftGet, nano_int); \
    AddFunction(PLL, FreqShiftAutoCenter, nano_int); \
    AddFunction(PLL, FreqExcOverwriteSet, nano_int, nano_int, nano_int); \
    AddFunction(PLL, FreqExcOverwriteGet, nano_int); \
    AddFunction(PLL, DemodInputSet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(PLL, DemodInputGet, nano_unsigned_int16); \
    AddFunction(PLL, DemodHarmonicSet, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(PLL, DemodHarmonicGet, nano_unsigned_int16); \
    AddFunction(PLL, DemodPhasRefSet, nano_unsigned_int16, nano_float32); \
    AddFunction(PLL, DemodPhasRefGet, nano_unsigned_int16); \
    AddFunction(PLL, DemodFilterSet, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(PLL, DemodFilterGet, nano_unsigned_int16);

#define AddPLLQCtrlFunctions \
    AddFunction(PLLQCtrl, AccessRequest, nano_unsigned_int32); \
    AddFunction(PLLQCtrl, AccessGet); \
    AddFunction(PLLQCtrl, OnOffSet, nano_unsigned_int32); \
    AddFunction(PLLQCtrl, OnOffGet); \
    AddFunction(PLLQCtrl, QGainSet, nano_float32); \
    AddFunction(PLLQCtrl, QGainGet); \
    AddFunction(PLLQCtrl, PhaseSet, nano_int, nano_float32); \
    AddFunction(PLLQCtrl, PhaseGet);

#define AddPLLFreqSwpFunctions \
    AddFunction(PLLFreqSwp, Open, nano_int); \
    AddFunction(PLLFreqSwp, ParamsSet, nano_int, nano_int, nano_float32, nano_float32); \
    AddFunction(PLLFreqSwp, ParamsGet, nano_int); \
    AddFunction(PLLFreqSwp, Start, nano_int, nano_unsigned_int32, nano_unsigned_int32); \
    AddFunction(PLLFreqSwp, Stop, nano_int);

#define AddPLLPhasSwpFunctions \
    AddFunction(PLLPhasSwp, Start, nano_int, nano_unsigned_int32); \
    AddFunction(PLLPhasSwp, Stop, nano_int);

#define AddPLLSignalAnlzrFunctions \
    AddFunction(PLLSignalAnlzr, Open); \
    AddFunction(PLLSignalAnlzr, ChSet, nano_int); \
    AddFunction(PLLSignalAnlzr, ChGet); \
    AddFunction(PLLSignalAnlzr, TimebaseSet, nano_int, nano_int); \
    AddFunction(PLLSignalAnlzr, TimebaseGet); \
    AddFunction(PLLSignalAnlzr, TrigAuto); \
    AddFunction(PLLSignalAnlzr, TrigRearm); \
    AddFunction(PLLSignalAnlzr, TrigSet, nano_unsigned_int16, nano_int, nano_unsigned_int16, nano_float64, nano_float64, nano_unsigned_int16); \
    AddFunction(PLLSignalAnlzr, TrigGet); \
    AddFunction(PLLSignalAnlzr, OsciDataGet); \
    AddFunction(PLLSignalAnlzr, FFTPropsSet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16, nano_int); \
    AddFunction(PLLSignalAnlzr, FFTPropsGet); \
    AddFunction(PLLSignalAnlzr, FFTAvgRestart); \
    AddFunction(PLLSignalAnlzr, FFTDataGet);

#define AddPLLZoomFFTFunctions \
    AddFunction(PLLZoomFFT, Open); \
    AddFunction(PLLZoomFFT, ChSet, nano_int); \
    AddFunction(PLLZoomFFT, ChGet); \
    AddFunction(PLLZoomFFT, AvgRestart); \
    AddFunction(PLLZoomFFT, PropsSet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16, nano_int); \
    AddFunction(PLLZoomFFT, PropsGet); \
    AddFunction(PLLZoomFFT, DataGet);

#define AddOCSyncFunctions \
    AddFunction(OCSync, AnglesSet, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddFunction(OCSync, AnglesGet); \
    AddFunction(OCSync, LinkAnglesSet, nano_unsigned_int32, nano_unsigned_int32); \
    AddFunction(OCSync, LinkAnglesGet);

#define AddScriptFunctions \
    AddFunction(Script, Load, nano_int, nano_string, nano_unsigned_int32); \
    AddFunction(Script, Save, nano_int, nano_string, nano_unsigned_int32); \
    AddFunction(Script, Deploy, nano_int); \
    AddFunction(Script, Undeploy, nano_int); \
    AddFunction(Script, Run, nano_int, nano_unsigned_int32); \
    AddFunction(Script, Stop); \
    AddFunction(Script, ChsGet, nano_unsigned_int16); \
    AddFunction(Script, ChsSet, nano_unsigned_int16, nano_int, nano_1D_array_int); \
    AddFunction(Script, DataGet, nano_unsigned_int16, nano_int); \
    AddFunction(Script, Autosave, nano_unsigned_int16, nano_int, nano_unsigned_int32);

#define AddInterfFunctions \
    AddFunction(Interf, CtrlOnOffSet, nano_unsigned_int32); \
    AddFunction(Interf, CtrlOnOffGet); \
    AddFunction(Interf, CtrlPropsSet, nano_float32, nano_float32, nano_unsigned_int32); \
    AddFunction(Interf, CtrlPropsGet); \
    AddFunction(Interf, WPiezoSet, nano_float32); \
    AddFunction(Interf, WPiezoGet); \
    AddFunction(Interf, ValGet); \
    AddFunction(Interf, CtrlCalibrOpen); \
    AddFunction(Interf, CtrlReset); \
    AddFunction(Interf, CtrlNullDefl);

#define AddLaserFunctions \
    AddFunction(Laser, OnOffSet, nano_unsigned_int32); \
    AddFunction(Laser, OnOffGet); \
    AddFunction(Laser, PropsSet, nano_float32); \
    AddFunction(Laser, PropsGet); \
    AddFunction(Laser, PowerGet);

#define AddBeamDeflFunctions \
    AddFunction(BeamDefl, HorConfigSet, nano_int, nano_string, nano_int, nano_string, nano_float32, nano_float32); \
    AddFunction(BeamDefl, HorConfigGet); \
    AddFunction(BeamDefl, VerConfigSet, nano_int, nano_string, nano_int, nano_string, nano_float32, nano_float32); \
    AddFunction(BeamDefl, VerConfigGet); \
    AddFunction(BeamDefl, IntConfigSet, nano_int, nano_string, nano_int, nano_string, nano_float32, nano_float32); \
    AddFunction(BeamDefl, IntConfigGet); \
    AddFunction(BeamDefl, AutoOffset, nano_unsigned_int16);

#define AddSignalsFunctions \
    AddFunction(Signals, NamesGet); \
    AddFunction(Signals, InSlotSet, nano_int, nano_int); \
    AddFunction(Signals, InSlotsGet); \
    AddFunction(Signals, CalibrGet, nano_int); \
    AddFunction(Signals, RangeGet, nano_int); \
    AddFunction(Signals, ValGet, nano_int, nano_unsigned_int32); \
    AddFunction(Signals, ValsGet, nano_int, nano_1D_array_int, nano_unsigned_int32); \
    AddFunction(Signals, MeasNamesGet); \
    AddFunction(Signals, AddRTGet); \
    AddFunction(Signals, AddRTSet, nano_int, nano_int);

#define AddUserInFunctions \
    AddFunction(UserIn, CalibrSet, nano_int, nano_int, nano_float32);

#define AddUserOutFunctions \
    AddFunction(UserOut, ModeSet, nano_int, nano_unsigned_int16); \
    AddFunction(UserOut, ModeGet, nano_int); \
    AddFunction(UserOut, MonitorChSet, nano_int, nano_int); \
    AddFunction(UserOut, MonitorChGet, nano_int); \
    AddFunction(UserOut, ValSet, nano_int, nano_float32); \
    AddFunction(UserOut, CalibrSet, nano_int, nano_float32, nano_float32); \
    AddFunction(UserOut, CalcSignalNameSet, nano_int, nano_int, nano_string); \
    AddFunction(UserOut, CalcSignalNameGet, nano_int); \
    AddFunction(UserOut, CalcSignalConfigSet, nano_int, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(UserOut, CalcSignalConfigGet, nano_int); \
    AddFunction(UserOut, LimitsSet, nano_int, nano_float32, nano_float32); \
    AddFunction(UserOut, LimitsGet, nano_int);

#define AddDigLinesFunctions \
    AddFunction(DigLines, PropsSet, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32); \
    AddFunction(DigLines, OutStatusSet, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32); \
    AddFunction(DigLines, TTLValGet, nano_unsigned_int16); \
    AddFunction(DigLines, Pulse, nano_unsigned_int16, nano_int, nano_1D_array_unsigned_int8, nano_float32, nano_float32, nano_int, nano_unsigned_int32);

#define AddDataLogFunctions \
    AddFunction(DataLog, Open); \
    AddFunction(DataLog, Start); \
    AddFunction(DataLog, Stop); \
    AddFunction(DataLog, StatusGet); \
    AddFunction(DataLog, ChsSet, nano_int, nano_1D_array_int); \
    AddFunction(DataLog, ChsGet); \
    AddFunction(DataLog, PropsSet, nano_unsigned_int16, nano_int, nano_int, nano_float32, nano_int, nano_int, nano_string, nano_int, nano_string, nano_int, nano_int, nano_1D_array_string); \
    AddFunction(DataLog, PropsGet);

#define AddTCPLogFunctions \
    AddFunction(TCPLog, Start); \
    AddFunction(TCPLog, Stop); \
    AddFunction(TCPLog, ChsSet, nano_int, nano_1D_array_int); \
    AddFunction(TCPLog, OversamplSet, nano_int); \
    AddFunction(TCPLog, StatusGet);

#define AddOsciHRFunctions \
    AddFunction(OsciHR, ChSet, nano_int); \
    AddFunction(OsciHR, ChGet); \
    AddFunction(OsciHR, OversamplSet, nano_int); \
    AddFunction(OsciHR, OversamplGet); \
    AddFunction(OsciHR, CalibrModeSet, nano_unsigned_int16); \
    AddFunction(OsciHR, CalibrModeGet); \
    AddFunction(OsciHR, SamplesSet, nano_int); \
    AddFunction(OsciHR, SamplesGet); \
    AddFunction(OsciHR, PreTrigSet, nano_unsigned_int32, nano_float64); \
    AddFunction(OsciHR, PreTrigGet); \
    AddFunction(OsciHR, Run); \
    AddFunction(OsciHR, OsciDataGet, nano_unsigned_int16, nano_float64); \
    AddFunction(OsciHR, TrigModeSet, nano_unsigned_int16); \
    AddFunction(OsciHR, TrigModeGet); \
    AddFunction(OsciHR, TrigLevChSet, nano_int); \
    AddFunction(OsciHR, TrigLevChGet); \
    AddFunction(OsciHR, TrigLevValSet, nano_float64); \
    AddFunction(OsciHR, TrigLevValGet); \
    AddFunction(OsciHR, TrigLevHystSet, nano_float64); \
    AddFunction(OsciHR, TrigLevHystGet); \
    AddFunction(OsciHR, TrigLevSlopeSet, nano_unsigned_int16); \
    AddFunction(OsciHR, TrigLevSlopeGet); \
    AddFunction(OsciHR, TrigDigChSet, nano_int); \
    AddFunction(OsciHR, TrigDigChGet); \
    AddFunction(OsciHR, TrigArmModeSet, nano_unsigned_int16); \
    AddFunction(OsciHR, TrigArmModeGet); \
    AddFunction(OsciHR, TrigDigSlopeSet, nano_unsigned_int16); \
    AddFunction(OsciHR, TrigDigSlopeGet); \
    AddFunction(OsciHR, TrigRearm); \
    AddFunction(OsciHR, PSDShow, nano_unsigned_int32); \
    AddFunction(OsciHR, PSDWeightSet, nano_unsigned_int16); \
    AddFunction(OsciHR, PSDWeightGet); \
    AddFunction(OsciHR, PSDWindowSet, nano_unsigned_int16); \
    AddFunction(OsciHR, PSDWindowGet); \
    AddFunction(OsciHR, PSDAvrgTypeSet, nano_unsigned_int16); \
    AddFunction(OsciHR, PSDAvrgTypeGet); \
    AddFunction(OsciHR, PSDAvrgCountSet, nano_int); \
    AddFunction(OsciHR, PSDAvrgCountGet); \
    AddFunction(OsciHR, PSDAvrgRestart); \
    AddFunction(OsciHR, PSDDataGet, nano_unsigned_int16, nano_float64);

#define AddOsci1TFunctions \
    AddFunction(Osci1T, ChSet, nano_int); \
    AddFunction(Osci1T, ChGet); \
    AddFunction(Osci1T, TimebaseSet, nano_int); \
    AddFunction(Osci1T, TimebaseGet); \
    AddFunction(Osci1T, TrigSet, nano_unsigned_int16, nano_unsigned_int16, nano_float64, nano_float64); \
    AddFunction(Osci1T, TrigGet); \
    AddFunction(Osci1T, Run); \
    AddFunction(Osci1T, DataGet, nano_unsigned_int16);

#define AddOsci2TFunctions \
    AddFunction(Osci2T, ChsSet, nano_int, nano_int); \
    AddFunction(Osci2T, ChsGet); \
    AddFunction(Osci2T, TimebaseSet, nano_unsigned_int16); \
    AddFunction(Osci2T, TimebaseGet); \
    AddFunction(Osci2T, OversamplSet, nano_unsigned_int16); \
    AddFunction(Osci2T, OversamplGet); \
    AddFunction(Osci2T, TrigSet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16, nano_float64, nano_float64, nano_float64); \
    AddFunction(Osci2T, TrigGet); \
    AddFunction(Osci2T, Run); \
    AddFunction(Osci2T, DataGet, nano_unsigned_int16);

#define AddSignalChartFunctions \
    AddFunction(SignalChart, Open); \
    AddFunction(SignalChart, ChsSet, nano_int, nano_int); \
    AddFunction(SignalChart, ChsGet);

#define AddSpectrumAnlzrFunctions \
    AddFunction(SpectrumAnlzr, ChSet, nano_int, nano_int); \
    AddFunction(SpectrumAnlzr, ChGet, nano_int); \
    AddFunction(SpectrumAnlzr, FreqRangeSet, nano_int, nano_int); \
    AddFunction(SpectrumAnlzr, FreqRangeGet, nano_int); \
    AddFunction(SpectrumAnlzr, FreqResSet, nano_int, nano_unsigned_int16); \
    AddFunction(SpectrumAnlzr, FreqResGet, nano_int); \
    AddFunction(SpectrumAnlzr, FFTWindowSet, nano_int, nano_unsigned_int16); \
    AddFunction(SpectrumAnlzr, FFTWindowGet, nano_int); \
    AddFunction(SpectrumAnlzr, AveragSet, nano_int, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int32); \
    AddFunction(SpectrumAnlzr, AveragGet, nano_int); \
    AddFunction(SpectrumAnlzr, ACCouplingSet, nano_int, nano_unsigned_int32); \
    AddFunction(SpectrumAnlzr, ACCouplingGet, nano_int); \
    AddFunction(SpectrumAnlzr, CursorPosSet, nano_int, nano_unsigned_int16, nano_float64, nano_float64); \
    AddFunction(SpectrumAnlzr, CursorPosGet, nano_int, nano_unsigned_int16); \
    AddFunction(SpectrumAnlzr, BandRMSGet, nano_int); \
    AddFunction(SpectrumAnlzr, DCGet, nano_int); \
    AddFunction(SpectrumAnlzr, Run, nano_int); \
    AddFunction(SpectrumAnlzr, DataGet, nano_int);

#define AddFunGen1ChFunctions \
    AddFunction(FunGen1Ch, Start, nano_int); \
    AddFunction(FunGen1Ch, Stop); \
    AddFunction(FunGen1Ch, StatusGet); \
    AddFunction(FunGen1Ch, PropsSet, nano_float32, nano_float32, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(FunGen1Ch, PropsGet); \
    AddFunction(FunGen1Ch, IdleSet, nano_float32); \
    AddFunction(FunGen1Ch, IdleGet);

#define AddFunGen2ChFunctions \
    AddFunction(FunGen2Ch, Start, nano_int); \
    AddFunction(FunGen2Ch, Stop); \
    AddFunction(FunGen2Ch, StatusGet); \
    AddFunction(FunGen2Ch, IdleSet, nano_int, nano_float32); \
    AddFunction(FunGen2Ch, IdleGet, nano_int); \
    AddFunction(FunGen2Ch, OnOffSet, nano_int, nano_unsigned_int32); \
    AddFunction(FunGen2Ch, OnOffGet, nano_int); \
    AddFunction(FunGen2Ch, SignalSet, nano_int, nano_int); \
    AddFunction(FunGen2Ch, SignalGet, nano_int); \
    AddFunction(FunGen2Ch, PropsSet, nano_int, nano_float32, nano_float32, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16); \
    AddFunction(FunGen2Ch, PropsGet, nano_int); \
    AddFunction(FunGen2Ch, WaveformSet, nano_int, nano_unsigned_int16); \
    AddFunction(FunGen2Ch, WaveformGet, nano_int);

#define AddUtilFunctions \
    AddFunction(Util, SessionPathGet); \
    AddFunction(Util, SettingsLoad, nano_int, nano_string, nano_unsigned_int32); \
    AddFunction(Util, SettingsSave, nano_int, nano_string, nano_unsigned_int32); \
    AddFunction(Util, LayoutLoad, nano_int, nano_string, nano_unsigned_int32); \
    AddFunction(Util, LayoutSave, nano_int, nano_string, nano_unsigned_int32); \
    AddFunction(Util, Lock); \
    AddFunction(Util, UnLock); \
    AddFunction(Util, RTFreqSet, nano_float32); \
    AddFunction(Util, RTFreqGet); \
    AddFunction(Util, AcqPeriodSet, nano_float32); \
    AddFunction(Util, AcqPeriodGet); \
    AddFunction(Util, RTOversamplSet, nano_int); \
    AddFunction(Util, RTOversamplGet); \
    AddFunction(Util, Quit, nano_unsigned_int32, nano_int, nano_string, nano_int, nano_string, nano_unsigned_int32);

#define AddDumpBiasFunctions \
    AddDumpFunction(Bias, Set); \
    AddDumpFunction(Bias, Get, nano_float32); \
    AddDumpFunction(Bias, RangeSet); \
    AddDumpFunction(Bias, RangeGet, nano_int, nano_int, nano_1D_array_string, nano_unsigned_int16); \
    AddDumpFunction(Bias, CalibrSet); \
    AddDumpFunction(Bias, CalibrGet, nano_float32, nano_float32); \
    AddDumpFunction(Bias, Pulse);

#define AddDumpBiasSwpFunctions \
    AddDumpFunction(BiasSwp, Open); \
    AddDumpFunction(BiasSwp, Start, nano_int, nano_int, nano_1D_array_string, nano_int, nano_int, nano_2D_array_float32); \
    AddDumpFunction(BiasSwp, PropsSet); \
    AddDumpFunction(BiasSwp, LimitsSet);

#define AddDumpBiasSpectrFunctions \
    AddDumpFunction(BiasSpectr, Open); \
    AddDumpFunction(BiasSpectr, Start, nano_int, nano_int, nano_1D_array_string, nano_int, nano_int, nano_2D_array_float32, nano_int, nano_1D_array_float32); \
    AddDumpFunction(BiasSpectr, Stop); \
    AddDumpFunction(BiasSpectr, StatusGet, nano_unsigned_int32); \
    AddDumpFunction(BiasSpectr, ChsSet); \
    AddDumpFunction(BiasSpectr, ChsGet, nano_int, nano_1D_array_int); \
    AddDumpFunction(BiasSpectr, PropsSet); \
    AddDumpFunction(BiasSpectr, PropsGet, nano_unsigned_int16, nano_int, nano_unsigned_int16, nano_int, nano_int, nano_int, nano_1D_array_string, nano_int, nano_int, nano_1D_array_string, nano_int, nano_int, nano_1D_array_string); \
    AddDumpFunction(BiasSpectr, AdvPropsSet); \
    AddDumpFunction(BiasSpectr, AdvPropsGet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16); \
    AddDumpFunction(BiasSpectr, LimitsSet); \
    AddDumpFunction(BiasSpectr, LimitsGet, nano_float32, nano_float32); \
    AddDumpFunction(BiasSpectr, TimingSet); \
    AddDumpFunction(BiasSpectr, TimingGet, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(BiasSpectr, TTLSyncSet); \
    AddDumpFunction(BiasSpectr, TTLSyncGet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16, nano_float32, nano_float32); \
    AddDumpFunction(BiasSpectr, AltZCtrlSet); \
    AddDumpFunction(BiasSpectr, AltZCtrlGet, nano_unsigned_int16, nano_float32, nano_float32); \
    AddDumpFunction(BiasSpectr, MLSLockinPerSegSet); \
    AddDumpFunction(BiasSpectr, MLSLockinPerSegGet, nano_unsigned_int32); \
    AddDumpFunction(BiasSpectr, MLSModeSet); \
    AddDumpFunction(BiasSpectr, MLSModeGet, nano_int, nano_string); \
    AddDumpFunction(BiasSpectr, MLSValsSet); \
    AddDumpFunction(BiasSpectr, MLSValsGet, nano_int, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_int, nano_1D_array_unsigned_int32);

#define AddDumpKelvinCtrlFunctions \
    AddDumpFunction(KelvinCtrl, CtrlOnOffSet); \
    AddDumpFunction(KelvinCtrl, CtrlOnOffGet, nano_unsigned_int32); \
    AddDumpFunction(KelvinCtrl, SetpntSet); \
    AddDumpFunction(KelvinCtrl, SetpntGet, nano_float32); \
    AddDumpFunction(KelvinCtrl, GainSet); \
    AddDumpFunction(KelvinCtrl, GainGet, nano_float32, nano_float32, nano_unsigned_int16); \
    AddDumpFunction(KelvinCtrl, ModParamsSet); \
    AddDumpFunction(KelvinCtrl, ModParamsGet, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(KelvinCtrl, ModOnOffSet); \
    AddDumpFunction(KelvinCtrl, ModOnOffGet, nano_unsigned_int16, nano_unsigned_int16); \
    AddDumpFunction(KelvinCtrl, CtrlSignalSet); \
    AddDumpFunction(KelvinCtrl, CtrlSignalGet, nano_int); \
    AddDumpFunction(KelvinCtrl, AmpGet, nano_float32); \
    AddDumpFunction(KelvinCtrl, BiasLimitsSet); \
    AddDumpFunction(KelvinCtrl, BiasLimitsGet, nano_float32, nano_float32);

#define AddDumpCPDCompFunctions \
    AddDumpFunction(CPDComp, Open); \
    AddDumpFunction(CPDComp, Close); \
    AddDumpFunction(CPDComp, ParamsSet); \
    AddDumpFunction(CPDComp, ParamsGet, nano_float32, nano_float32, nano_int); \
    AddDumpFunction(CPDComp, DataGet, nano_int, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_float32, nano_int, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_float32, nano_float32, nano_float64, nano_float64);

#define AddDumpCurrentFunctions \
    AddDumpFunction(Current, Get, nano_float32); \
    AddDumpFunction(Current, Get100, nano_float32); \
    AddDumpFunction(Current, BEEMGet, nano_float32); \
    AddDumpFunction(Current, GainSet); \
    AddDumpFunction(Current, GainsGet, nano_int, nano_int, nano_1D_array_string, nano_unsigned_int16); \
    AddDumpFunction(Current, CalibrSet); \
    AddDumpFunction(Current, CalibrGet, nano_float64, nano_float64);

#define AddDumpZCtrlFunctions \
    AddDumpFunction(ZCtrl, ZPosSet); \
    AddDumpFunction(ZCtrl, ZPosGet, nano_float32); \
    AddDumpFunction(ZCtrl, OnOffSet); \
    AddDumpFunction(ZCtrl, OnOffGet, nano_unsigned_int32); \
    AddDumpFunction(ZCtrl, SetpntSet); \
    AddDumpFunction(ZCtrl, SetpntGet, nano_float32); \
    AddDumpFunction(ZCtrl, GainSet); \
    AddDumpFunction(ZCtrl, GainGet, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(ZCtrl, SwitchOffDelaySet); \
    AddDumpFunction(ZCtrl, SwitchOffDelayGet, nano_float32); \
    AddDumpFunction(ZCtrl, TipLiftSet); \
    AddDumpFunction(ZCtrl, TipLiftGet, nano_float32); \
    AddDumpFunction(ZCtrl, Home); \
    AddDumpFunction(ZCtrl, HomePropsSet); \
    AddDumpFunction(ZCtrl, HomePropsGet, nano_unsigned_int16, nano_float32); \
    AddDumpFunction(ZCtrl, ActiveCtrlSet); \
    AddDumpFunction(ZCtrl, CtrlListGet, nano_int, nano_int, nano_1D_array_string, nano_int); \
    AddDumpFunction(ZCtrl, Withdraw); \
    AddDumpFunction(ZCtrl, WithdrawRateSet); \
    AddDumpFunction(ZCtrl, WithdrawRateGet, nano_float32); \
    AddDumpFunction(ZCtrl, LimitsEnabledSet); \
    AddDumpFunction(ZCtrl, LimitsEnabledGet, nano_unsigned_int32); \
    AddDumpFunction(ZCtrl, LimitsSet); \
    AddDumpFunction(ZCtrl, LimitsGet, nano_float32, nano_float32); \
    AddDumpFunction(ZCtrl, StatusGet, nano_unsigned_int16);

#define AddDumpSafeTipFunctions \
    AddDumpFunction(SafeTip, OnOffSet); \
    AddDumpFunction(SafeTip, OnOffGet, nano_unsigned_int16); \
    AddDumpFunction(SafeTip, SignalGet, nano_float32); \
    AddDumpFunction(SafeTip, PropsSet); \
    AddDumpFunction(SafeTip, PropsGet, nano_unsigned_int16, nano_unsigned_int16, nano_float32);

#define AddDumpAutoApproachFunctions \
    AddDumpFunction(AutoApproach, Open); \
    AddDumpFunction(AutoApproach, OnOffSet); \
    AddDumpFunction(AutoApproach, OnOffGet, nano_unsigned_int16);

#define AddDumpZSpectrFunctions \
    AddDumpFunction(ZSpectr, Open); \
    AddDumpFunction(ZSpectr, Start, nano_int, nano_int, nano_1D_array_string, nano_int, nano_int, nano_2D_array_float32, nano_int, nano_1D_array_float32); \
    AddDumpFunction(ZSpectr, Stop); \
    AddDumpFunction(ZSpectr, StatusGet, nano_unsigned_int32); \
    AddDumpFunction(ZSpectr, ChsSet); \
    AddDumpFunction(ZSpectr, ChsGet, nano_int, nano_1D_array_int); \
    AddDumpFunction(ZSpectr, PropsSet); \
    AddDumpFunction(ZSpectr, PropsGet, nano_unsigned_int16, nano_int, nano_int, nano_int, nano_1D_array_string, nano_int, nano_int, nano_1D_array_string, nano_int, nano_int, nano_1D_array_string, nano_unsigned_int16, nano_unsigned_int16); \
    AddDumpFunction(ZSpectr, AdvPropsSet); \
    AddDumpFunction(ZSpectr, AdvPropsGet, nano_float32, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16); \
    AddDumpFunction(ZSpectr, RangeSet); \
    AddDumpFunction(ZSpectr, RangeGet, nano_float32, nano_float32); \
    AddDumpFunction(ZSpectr, TimingSet); \
    AddDumpFunction(ZSpectr, TimingGet, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(ZSpectr, RetractDelaySet); \
    AddDumpFunction(ZSpectr, RetractDelayGet, nano_float32); \
    AddDumpFunction(ZSpectr, RetractSet); \
    AddDumpFunction(ZSpectr, RetractGet, nano_unsigned_int16, nano_float32, nano_int, nano_unsigned_int16); \
    AddDumpFunction(ZSpectr, Retract2ndSet); \
    AddDumpFunction(ZSpectr, Retract2ndGet, nano_int, nano_float32, nano_int, nano_unsigned_int16);

#define AddDumpPiezoFunctions \
    AddDumpFunction(Piezo, TiltSet); \
    AddDumpFunction(Piezo, TiltGet, nano_float32, nano_float32); \
    AddDumpFunction(Piezo, RangeSet); \
    AddDumpFunction(Piezo, RangeGet, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(Piezo, SensSet); \
    AddDumpFunction(Piezo, SensGet, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(Piezo, DriftCompSet); \
    AddDumpFunction(Piezo, DriftCompGet, nano_unsigned_int32, nano_float32, nano_float32, nano_float32, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32); \
    AddDumpFunction(Piezo, CalibrGet, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(Piezo, HVAInfoGet, nano_float32, nano_float32, nano_float32, nano_float32, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32); \
    AddDumpFunction(Piezo, HVAStatusLEDGet, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32);

#define AddDumpScanFunctions \
    AddDumpFunction(Scan, Action); \
    AddDumpFunction(Scan, StatusGet, nano_unsigned_int32); \
    AddDumpFunction(Scan, WaitEndOfScan, nano_unsigned_int32, nano_unsigned_int32, nano_string); \
    AddDumpFunction(Scan, FrameSet); \
    AddDumpFunction(Scan, FrameGet, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(Scan, BufferSet); \
    AddDumpFunction(Scan, BufferGet, nano_int, nano_1D_array_int, nano_int, nano_int); \
    AddDumpFunction(Scan, PropsSet); \
    AddDumpFunction(Scan, PropsGet, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32, nano_int, nano_string, nano_int, nano_string); \
    AddDumpFunction(Scan, SpeedSet); \
    AddDumpFunction(Scan, SpeedGet, nano_float32, nano_float32, nano_float32, nano_float32, nano_unsigned_int16, nano_float32); \
    AddDumpFunction(Scan, FrameDataGrab, nano_int, nano_string, nano_int, nano_int, nano_2D_array_float32, nano_unsigned_int32);

#define AddDumpFolMeFunctions \
    AddDumpFunction(FolMe, XYPosSet); \
    AddDumpFunction(FolMe, XYPosGet, nano_float64, nano_float64); \
    AddDumpFunction(FolMe, SpeedSet); \
    AddDumpFunction(FolMe, SpeedGet, nano_float32, nano_unsigned_int32); \
    AddDumpFunction(FolMe, OversamplSet); \
    AddDumpFunction(FolMe, OversamplGet, nano_int, nano_float32); \
    AddDumpFunction(FolMe, Stop); \
    AddDumpFunction(FolMe, PSOnOffGet, nano_unsigned_int32); \
    AddDumpFunction(FolMe, PSOnOffSet); \
    AddDumpFunction(FolMe, PSExpGet, nano_unsigned_int16, nano_int, nano_int, nano_1D_array_string); \
    AddDumpFunction(FolMe, PSExpSet); \
    AddDumpFunction(FolMe, PSPropsGet, nano_unsigned_int32, nano_unsigned_int32, nano_int, nano_string, nano_int, nano_string, nano_float32); \
    AddDumpFunction(FolMe, PSPropsSet);

#define AddDumpTipRecFunctions \
    AddDumpFunction(TipRec, BufferSizeSet); \
    AddDumpFunction(TipRec, BufferSizeGet, nano_int); \
    AddDumpFunction(TipRec, BufferClear); \
    AddDumpFunction(TipRec, DataGet, nano_int, nano_1D_array_int, nano_int, nano_int, nano_2D_array_float32); \
    AddDumpFunction(TipRec, DataSave);

#define AddDumpPatternFunctions \
    AddDumpFunction(Pattern, ExpOpen); \
    AddDumpFunction(Pattern, ExpStart); \
    AddDumpFunction(Pattern, ExpPause); \
    AddDumpFunction(Pattern, ExpStop); \
    AddDumpFunction(Pattern, ExpStatusGet, nano_unsigned_int32); \
    AddDumpFunction(Pattern, GridSet); \
    AddDumpFunction(Pattern, GridGet, nano_int, nano_int, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(Pattern, LineSet); \
    AddDumpFunction(Pattern, LineGet, nano_int, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(Pattern, CloudSet); \
    AddDumpFunction(Pattern, CloudGet, nano_int, nano_1D_array_float32, nano_1D_array_float32); \
    AddDumpFunction(Pattern, PropsSet); \
    AddDumpFunction(Pattern, PropsGet, nano_int, nano_int, nano_1D_array_string, nano_int, nano_string, nano_int, nano_string, nano_float32, nano_unsigned_int32);

#define AddDumpMarksFunctions \
    AddDumpFunction(Marks, PointDraw); \
    AddDumpFunction(Marks, PointsDraw); \
    AddDumpFunction(Marks, LineDraw); \
    AddDumpFunction(Marks, LinesDraw); \
    AddDumpFunction(Marks, PointsErase); \
    AddDumpFunction(Marks, LinesErase); \
    AddDumpFunction(Marks, PointsVisibleSet); \
    AddDumpFunction(Marks, LinesVisibleSet); \
    AddDumpFunction(Marks, PointsGet, nano_int, nano_1D_array_float32, nano_1D_array_float32, nano_int, nano_1D_array_string, nano_1D_array_unsigned_int32, nano_1D_array_unsigned_int32); \
    AddDumpFunction(Marks, LinesGet, nano_int, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_float32, nano_1D_array_unsigned_int32, nano_1D_array_unsigned_int32);

#define AddDumpTipShaperFunctions \
    AddDumpFunction(TipShaper, Start); \
    AddDumpFunction(TipShaper, PropsSet); \
    AddDumpFunction(TipShaper, PropsGet, nano_float32, nano_unsigned_int32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32, nano_unsigned_int32);

#define AddDumpMotorFunctions \
    AddDumpFunction(Motor, StartMove); \
    AddDumpFunction(Motor, StartClosedLoop); \
    AddDumpFunction(Motor, StopMove); \
    AddDumpFunction(Motor, PosGet, nano_float64, nano_float64, nano_float64); \
    AddDumpFunction(Motor, StepCounterGet, nano_int, nano_int, nano_int); \
    AddDumpFunction(Motor, FreqAmpGet, nano_float32, nano_float32); \
    AddDumpFunction(Motor, FreqAmpSet);

#define AddDumpGenSwpFunctions \
    AddDumpFunction(GenSwp, AcqChsSet); \
    AddDumpFunction(GenSwp, AcqChsGet, nano_int, nano_1D_array_int); \
    AddDumpFunction(GenSwp, SwpSignalSet); \
    AddDumpFunction(GenSwp, SwpSignalGet, nano_int, nano_string, nano_int, nano_int, nano_1D_array_string); \
    AddDumpFunction(GenSwp, LimitsSet); \
    AddDumpFunction(GenSwp, LimitsGet, nano_float32, nano_float32); \
    AddDumpFunction(GenSwp, PropsSet); \
    AddDumpFunction(GenSwp, PropsGet, nano_float32, nano_float32, nano_int, nano_unsigned_int16, nano_unsigned_int32, nano_unsigned_int32, nano_float32); \
    AddDumpFunction(GenSwp, Start, nano_int, nano_int, nano_1D_array_string, nano_int, nano_int, nano_2D_array_float32); \
    AddDumpFunction(GenSwp, Stop); \
    AddDumpFunction(GenSwp, Open);

#define AddDumpGenPICtrlFunctions \
    AddDumpFunction(GenPICtrl, OnOffSet); \
    AddDumpFunction(GenPICtrl, OnOffGet, nano_unsigned_int32); \
    AddDumpFunction(GenPICtrl, AOValSet); \
    AddDumpFunction(GenPICtrl, AOValGet, nano_float32); \
    AddDumpFunction(GenPICtrl, AOPropsSet); \
    AddDumpFunction(GenPICtrl, AOPropsGet, nano_int, nano_string, nano_int, nano_string, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(GenPICtrl, ModChSet); \
    AddDumpFunction(GenPICtrl, ModChGet, nano_int); \
    AddDumpFunction(GenPICtrl, DemodChSet); \
    AddDumpFunction(GenPICtrl, DemodChGet, nano_int); \
    AddDumpFunction(GenPICtrl, PropsSet); \
    AddDumpFunction(GenPICtrl, PropsGet, nano_float32, nano_float32, nano_float32, nano_unsigned_int16);

#define AddDumpAtomTrackFunctions \
    AddDumpFunction(AtomTrack, CtrlSet); \
    AddDumpFunction(AtomTrack, StatusGet, nano_unsigned_int16); \
    AddDumpFunction(AtomTrack, PropsSet); \
    AddDumpFunction(AtomTrack, PropsGet, nano_float32, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(AtomTrack, QuickCompStart); \
    AddDumpFunction(AtomTrack, DriftComp);

#define AddDumpLockInFunctions \
    AddDumpFunction(LockIn, ModOnOffSet, nano_int); \
    AddDumpFunction(LockIn, ModOnOffGet, nano_int, nano_unsigned_int32); \
    AddDumpFunction(LockIn, ModSignalSet, nano_int); \
    AddDumpFunction(LockIn, ModSignalGet, nano_int, nano_int); \
    AddDumpFunction(LockIn, ModPhasRegSet, nano_int); \
    AddDumpFunction(LockIn, ModPhasRegGet, nano_int, nano_int); \
    AddDumpFunction(LockIn, ModHarmonicSet, nano_int); \
    AddDumpFunction(LockIn, ModHarmonicGet, nano_int, nano_int); \
    AddDumpFunction(LockIn, ModPhasSet, nano_int); \
    AddDumpFunction(LockIn, ModPhasGet, nano_int, nano_float32); \
    AddDumpFunction(LockIn, ModAmpSet, nano_int); \
    AddDumpFunction(LockIn, ModAmpGet, nano_int, nano_float32); \
    AddDumpFunction(LockIn, ModPhasFreqSet, nano_int); \
    AddDumpFunction(LockIn, ModPhasFreqGet, nano_int, nano_float32); \
    AddDumpFunction(LockIn, DemodSignalSet, nano_int); \
    AddDumpFunction(LockIn, DemodSignalGet, nano_int, nano_int); \
    AddDumpFunction(LockIn, DemodHarmonicSet, nano_int); \
    AddDumpFunction(LockIn, DemodHarmonicGet, nano_int, nano_int); \
    AddDumpFunction(LockIn, DemodHPFilterSet, nano_int); \
    AddDumpFunction(LockIn, DemodHPFilterGet, nano_int, nano_int, nano_float32); \
    AddDumpFunction(LockIn, DemodLPFilterSet, nano_int); \
    AddDumpFunction(LockIn, DemodLPFilterGet, nano_int, nano_int, nano_float32); \
    AddDumpFunction(LockIn, DemodPhasRegSet, nano_int); \
    AddDumpFunction(LockIn, DemodPhasRegGet, nano_int, nano_int); \
    AddDumpFunction(LockIn, DemodPhasSet, nano_int); \
    AddDumpFunction(LockIn, DemodPhasGet, nano_int, nano_float32); \
    AddDumpFunction(LockIn, DemodSyncFilterSet, nano_int); \
    AddDumpFunction(LockIn, DemodSyncFilterGet, nano_int, nano_unsigned_int32); \
    AddDumpFunction(LockIn, DemodRTSignalsSet, nano_int); \
    AddDumpFunction(LockIn, DemodRTSignalsGet, nano_int, nano_unsigned_int32);

// Not updated
#define AddDumpLockInFreqSwpFunctions \
    AddDumpFunction(LockInFreqSwp, Open); \
    AddDumpFunction(LockInFreqSwp, Start, nano_unsigned_int32, nano_unsigned_int32); \
    AddDumpFunction(LockInFreqSwp, SignalSet, nano_int); \
    AddDumpFunction(LockInFreqSwp, SignalGet); \
    AddDumpFunction(LockInFreqSwp, LimitsSet, nano_float32, nano_float32); \
    AddDumpFunction(LockInFreqSwp, LimitsGet); \
    AddDumpFunction(LockInFreqSwp, PropsSet, nano_unsigned_int16, nano_unsigned_int16, nano_float32, nano_unsigned_int16, nano_float32, nano_unsigned_int32, nano_unsigned_int32, nano_int, nano_string); \
    AddDumpFunction(LockInFreqSwp, PropsGet);

#define AddDumpPLLFunctions \
    AddDumpFunction(PLL, InpCalibrSet, nano_int, nano_float32); \
    AddDumpFunction(PLL, InpCalibrGet, nano_int); \
    AddDumpFunction(PLL, InpRangeSet, nano_int, nano_float32); \
    AddDumpFunction(PLL, InpRangeGet, nano_int); \
    AddDumpFunction(PLL, InpPropsSet, nano_int, nano_unsigned_int16, nano_unsigned_int16); \
    AddDumpFunction(PLL, InpPropsGet, nano_int); \
    AddDumpFunction(PLL, AddOnOffSet, nano_int, nano_unsigned_int32); \
    AddDumpFunction(PLL, AddOnOffGet, nano_int); \
    AddDumpFunction(PLL, OutOnOffSet, nano_int, nano_unsigned_int32); \
    AddDumpFunction(PLL, OutOnOffGet, nano_int); \
    AddDumpFunction(PLL, ExcRangeSet, nano_int, nano_unsigned_int16); \
    AddDumpFunction(PLL, ExcRangeGet, nano_int); \
    AddDumpFunction(PLL, ExcitationSet, nano_int, nano_float32); \
    AddDumpFunction(PLL, ExcitationGet, nano_int); \
    AddDumpFunction(PLL, AmpCtrlSetpntSet, nano_int, nano_float32); \
    AddDumpFunction(PLL, AmpCtrlSetpntGet, nano_int); \
    AddDumpFunction(PLL, AmpCtrlOnOffSet, nano_int, nano_unsigned_int32); \
    AddDumpFunction(PLL, AmpCtrlOnOffGet, nano_int); \
    AddDumpFunction(PLL, AmpCtrlGainSet, nano_int, nano_float32, nano_float32); \
    AddDumpFunction(PLL, AmpCtrlGainGet, nano_int); \
    AddDumpFunction(PLL, AmpCtrlBandwidthSet, nano_int, nano_float32); \
    AddDumpFunction(PLL, AmpCtrlBandwidthGet, nano_int); \
    AddDumpFunction(PLL, PhasCtrlOnOffSet, nano_int, nano_unsigned_int32); \
    AddDumpFunction(PLL, PhasCtrlOnOffGet, nano_int); \
    AddDumpFunction(PLL, PhasCtrlGainSet, nano_int, nano_float32, nano_float32); \
    AddDumpFunction(PLL, PhasCtrlGainGet, nano_int); \
    AddDumpFunction(PLL, PhasCtrlBandwidthSet, nano_int, nano_float32); \
    AddDumpFunction(PLL, PhasCtrlBandwidthGet, nano_int); \
    AddDumpFunction(PLL, FreqRangeSet, nano_int, nano_float32); \
    AddDumpFunction(PLL, FreqRangeGet, nano_int); \
    AddDumpFunction(PLL, CenterFreqSet, nano_int, nano_float64); \
    AddDumpFunction(PLL, CenterFreqGet, nano_int); \
    AddDumpFunction(PLL, FreqShiftSet, nano_int, nano_float32); \
    AddDumpFunction(PLL, FreqShiftGet, nano_int); \
    AddDumpFunction(PLL, FreqShiftAutoCenter, nano_int); \
    AddDumpFunction(PLL, FreqExcOverwriteSet, nano_int, nano_int, nano_int); \
    AddDumpFunction(PLL, FreqExcOverwriteGet, nano_int); \
    AddDumpFunction(PLL, DemodInputSet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16); \
    AddDumpFunction(PLL, DemodInputGet, nano_unsigned_int16); \
    AddDumpFunction(PLL, DemodHarmonicSet, nano_unsigned_int16, nano_unsigned_int16); \
    AddDumpFunction(PLL, DemodHarmonicGet, nano_unsigned_int16); \
    AddDumpFunction(PLL, DemodPhasRefSet, nano_unsigned_int16, nano_float32); \
    AddDumpFunction(PLL, DemodPhasRefGet, nano_unsigned_int16); \
    AddDumpFunction(PLL, DemodFilterSet, nano_unsigned_int16, nano_unsigned_int16); \
    AddDumpFunction(PLL, DemodFilterGet, nano_unsigned_int16);

#define AddDumpPLLQCtrlFunctions \
    AddDumpFunction(PLLQCtrl, AccessRequest, nano_unsigned_int32); \
    AddDumpFunction(PLLQCtrl, AccessGet); \
    AddDumpFunction(PLLQCtrl, OnOffSet, nano_unsigned_int32); \
    AddDumpFunction(PLLQCtrl, OnOffGet); \
    AddDumpFunction(PLLQCtrl, QGainSet, nano_float32); \
    AddDumpFunction(PLLQCtrl, QGainGet); \
    AddDumpFunction(PLLQCtrl, PhaseSet, nano_int, nano_float32); \
    AddDumpFunction(PLLQCtrl, PhaseGet);

#define AddDumpPLLFreqSwpFunctions \
    AddDumpFunction(PLLFreqSwp, Open, nano_int); \
    AddDumpFunction(PLLFreqSwp, ParamsSet, nano_int, nano_int, nano_float32, nano_float32); \
    AddDumpFunction(PLLFreqSwp, ParamsGet, nano_int); \
    AddDumpFunction(PLLFreqSwp, Start, nano_int, nano_unsigned_int32, nano_unsigned_int32); \
    AddDumpFunction(PLLFreqSwp, Stop, nano_int);

#define AddDumpPLLPhasSwpFunctions \
    AddDumpFunction(PLLPhasSwp, Start, nano_int, nano_unsigned_int32); \
    AddDumpFunction(PLLPhasSwp, Stop, nano_int);

#define AddDumpPLLSignalAnlzrFunctions \
    AddDumpFunction(PLLSignalAnlzr, Open); \
    AddDumpFunction(PLLSignalAnlzr, ChSet, nano_int); \
    AddDumpFunction(PLLSignalAnlzr, ChGet); \
    AddDumpFunction(PLLSignalAnlzr, TimebaseSet, nano_int, nano_int); \
    AddDumpFunction(PLLSignalAnlzr, TimebaseGet); \
    AddDumpFunction(PLLSignalAnlzr, TrigAuto); \
    AddDumpFunction(PLLSignalAnlzr, TrigRearm); \
    AddDumpFunction(PLLSignalAnlzr, TrigSet, nano_unsigned_int16, nano_int, nano_unsigned_int16, nano_float64, nano_float64, nano_unsigned_int16); \
    AddDumpFunction(PLLSignalAnlzr, TrigGet); \
    AddDumpFunction(PLLSignalAnlzr, OsciDataGet); \
    AddDumpFunction(PLLSignalAnlzr, FFTPropsSet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16, nano_int); \
    AddDumpFunction(PLLSignalAnlzr, FFTPropsGet); \
    AddDumpFunction(PLLSignalAnlzr, FFTAvgRestart); \
    AddDumpFunction(PLLSignalAnlzr, FFTDataGet);

#define AddDumpPLLZoomFFTFunctions \
    AddDumpFunction(PLLZoomFFT, Open); \
    AddDumpFunction(PLLZoomFFT, ChSet, nano_int); \
    AddDumpFunction(PLLZoomFFT, ChGet); \
    AddDumpFunction(PLLZoomFFT, AvgRestart); \
    AddDumpFunction(PLLZoomFFT, PropsSet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16, nano_int); \
    AddDumpFunction(PLLZoomFFT, PropsGet); \
    AddDumpFunction(PLLZoomFFT, DataGet);

#define AddDumpOCSyncFunctions \
    AddDumpFunction(OCSync, AnglesSet, nano_float32, nano_float32, nano_float32, nano_float32); \
    AddDumpFunction(OCSync, AnglesGet); \
    AddDumpFunction(OCSync, LinkAnglesSet, nano_unsigned_int32, nano_unsigned_int32); \
    AddDumpFunction(OCSync, LinkAnglesGet);

#define AddDumpScriptFunctions \
    AddDumpFunction(Script, Load, nano_int, nano_string, nano_unsigned_int32); \
    AddDumpFunction(Script, Save, nano_int, nano_string, nano_unsigned_int32); \
    AddDumpFunction(Script, Deploy, nano_int); \
    AddDumpFunction(Script, Undeploy, nano_int); \
    AddDumpFunction(Script, Run, nano_int, nano_unsigned_int32); \
    AddDumpFunction(Script, Stop); \
    AddDumpFunction(Script, ChsGet, nano_unsigned_int16); \
    AddDumpFunction(Script, ChsSet, nano_unsigned_int16, nano_int, nano_1D_array_int); \
    AddDumpFunction(Script, DataGet, nano_unsigned_int16, nano_int); \
    AddDumpFunction(Script, Autosave, nano_unsigned_int16, nano_int, nano_unsigned_int32);

#define AddDumpInterfFunctions \
    AddDumpFunction(Interf, CtrlOnOffSet, nano_unsigned_int32); \
    AddDumpFunction(Interf, CtrlOnOffGet); \
    AddDumpFunction(Interf, CtrlPropsSet, nano_float32, nano_float32, nano_unsigned_int32); \
    AddDumpFunction(Interf, CtrlPropsGet); \
    AddDumpFunction(Interf, WPiezoSet, nano_float32); \
    AddDumpFunction(Interf, WPiezoGet); \
    AddDumpFunction(Interf, ValGet); \
    AddDumpFunction(Interf, CtrlCalibrOpen); \
    AddDumpFunction(Interf, CtrlReset); \
    AddDumpFunction(Interf, CtrlNullDefl);

#define AddDumpLaserFunctions \
    AddDumpFunction(Laser, OnOffSet, nano_unsigned_int32); \
    AddDumpFunction(Laser, OnOffGet); \
    AddDumpFunction(Laser, PropsSet, nano_float32); \
    AddDumpFunction(Laser, PropsGet); \
    AddDumpFunction(Laser, PowerGet);

#define AddDumpBeamDeflFunctions \
    AddDumpFunction(BeamDefl, HorConfigSet, nano_int, nano_string, nano_int, nano_string, nano_float32, nano_float32); \
    AddDumpFunction(BeamDefl, HorConfigGet); \
    AddDumpFunction(BeamDefl, VerConfigSet, nano_int, nano_string, nano_int, nano_string, nano_float32, nano_float32); \
    AddDumpFunction(BeamDefl, VerConfigGet); \
    AddDumpFunction(BeamDefl, IntConfigSet, nano_int, nano_string, nano_int, nano_string, nano_float32, nano_float32); \
    AddDumpFunction(BeamDefl, IntConfigGet); \
    AddDumpFunction(BeamDefl, AutoOffset, nano_unsigned_int16);

#define AddDumpSignalsFunctions \
    AddDumpFunction(Signals, NamesGet); \
    AddDumpFunction(Signals, InSlotSet, nano_int, nano_int); \
    AddDumpFunction(Signals, InSlotsGet); \
    AddDumpFunction(Signals, CalibrGet, nano_int); \
    AddDumpFunction(Signals, RangeGet, nano_int); \
    AddDumpFunction(Signals, ValGet, nano_int, nano_unsigned_int32); \
    AddDumpFunction(Signals, ValsGet, nano_int, nano_1D_array_int, nano_unsigned_int32); \
    AddDumpFunction(Signals, MeasNamesGet); \
    AddDumpFunction(Signals, AddRTGet); \
    AddDumpFunction(Signals, AddRTSet, nano_int, nano_int);

#define AddDumpUserInFunctions \
    AddDumpFunction(UserIn, CalibrSet, nano_int, nano_int, nano_float32);

#define AddDumpUserOutFunctions \
    AddDumpFunction(UserOut, ModeSet, nano_int, nano_unsigned_int16); \
    AddDumpFunction(UserOut, ModeGet, nano_int); \
    AddDumpFunction(UserOut, MonitorChSet, nano_int, nano_int); \
    AddDumpFunction(UserOut, MonitorChGet, nano_int); \
    AddDumpFunction(UserOut, ValSet, nano_int, nano_float32); \
    AddDumpFunction(UserOut, CalibrSet, nano_int, nano_float32, nano_float32); \
    AddDumpFunction(UserOut, CalcSignalNameSet, nano_int, nano_int, nano_string); \
    AddDumpFunction(UserOut, CalcSignalNameGet, nano_int); \
    AddDumpFunction(UserOut, CalcSignalConfigSet, nano_int, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16); \
    AddDumpFunction(UserOut, CalcSignalConfigGet, nano_int); \
    AddDumpFunction(UserOut, LimitsSet, nano_int, nano_float32, nano_float32); \
    AddDumpFunction(UserOut, LimitsGet, nano_int);

#define AddDumpDigLinesFunctions \
    AddDumpFunction(DigLines, PropsSet, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32); \
    AddDumpFunction(DigLines, OutStatusSet, nano_unsigned_int32, nano_unsigned_int32, nano_unsigned_int32); \
    AddDumpFunction(DigLines, TTLValGet, nano_unsigned_int16); \
    AddDumpFunction(DigLines, Pulse, nano_unsigned_int16, nano_int, nano_1D_array_unsigned_int8, nano_float32, nano_float32, nano_int, nano_unsigned_int32);

#define AddDumpDataLogFunctions \
    AddDumpFunction(DataLog, Open); \
    AddDumpFunction(DataLog, Start); \
    AddDumpFunction(DataLog, Stop); \
    AddDumpFunction(DataLog, StatusGet); \
    AddDumpFunction(DataLog, ChsSet, nano_int, nano_1D_array_int); \
    AddDumpFunction(DataLog, ChsGet); \
    AddDumpFunction(DataLog, PropsSet, nano_unsigned_int16, nano_int, nano_int, nano_float32, nano_int, nano_int, nano_string, nano_int, nano_string, nano_int, nano_int, nano_1D_array_string); \
    AddDumpFunction(DataLog, PropsGet);

#define AddDumpTCPLogFunctions \
    AddDumpFunction(TCPLog, Start); \
    AddDumpFunction(TCPLog, Stop); \
    AddDumpFunction(TCPLog, ChsSet, nano_int, nano_1D_array_int); \
    AddDumpFunction(TCPLog, OversamplSet, nano_int); \
    AddDumpFunction(TCPLog, StatusGet);

#define AddDumpOsciHRFunctions \
    AddDumpFunction(OsciHR, ChSet, nano_int); \
    AddDumpFunction(OsciHR, ChGet); \
    AddDumpFunction(OsciHR, OversamplSet, nano_int); \
    AddDumpFunction(OsciHR, OversamplGet); \
    AddDumpFunction(OsciHR, CalibrModeSet, nano_unsigned_int16); \
    AddDumpFunction(OsciHR, CalibrModeGet); \
    AddDumpFunction(OsciHR, SamplesSet, nano_int); \
    AddDumpFunction(OsciHR, SamplesGet); \
    AddDumpFunction(OsciHR, PreTrigSet, nano_unsigned_int32, nano_float64); \
    AddDumpFunction(OsciHR, PreTrigGet); \
    AddDumpFunction(OsciHR, Run); \
    AddDumpFunction(OsciHR, OsciDataGet, nano_unsigned_int16, nano_float64); \
    AddDumpFunction(OsciHR, TrigModeSet, nano_unsigned_int16); \
    AddDumpFunction(OsciHR, TrigModeGet); \
    AddDumpFunction(OsciHR, TrigLevChSet, nano_int); \
    AddDumpFunction(OsciHR, TrigLevChGet); \
    AddDumpFunction(OsciHR, TrigLevValSet, nano_float64); \
    AddDumpFunction(OsciHR, TrigLevValGet); \
    AddDumpFunction(OsciHR, TrigLevHystSet, nano_float64); \
    AddDumpFunction(OsciHR, TrigLevHystGet); \
    AddDumpFunction(OsciHR, TrigLevSlopeSet, nano_unsigned_int16); \
    AddDumpFunction(OsciHR, TrigLevSlopeGet); \
    AddDumpFunction(OsciHR, TrigDigChSet, nano_int); \
    AddDumpFunction(OsciHR, TrigDigChGet); \
    AddDumpFunction(OsciHR, TrigArmModeSet, nano_unsigned_int16); \
    AddDumpFunction(OsciHR, TrigArmModeGet); \
    AddDumpFunction(OsciHR, TrigDigSlopeSet, nano_unsigned_int16); \
    AddDumpFunction(OsciHR, TrigDigSlopeGet); \
    AddDumpFunction(OsciHR, TrigRearm); \
    AddDumpFunction(OsciHR, PSDShow, nano_unsigned_int32); \
    AddDumpFunction(OsciHR, PSDWeightSet, nano_unsigned_int16); \
    AddDumpFunction(OsciHR, PSDWeightGet); \
    AddDumpFunction(OsciHR, PSDWindowSet, nano_unsigned_int16); \
    AddDumpFunction(OsciHR, PSDWindowGet); \
    AddDumpFunction(OsciHR, PSDAvrgTypeSet, nano_unsigned_int16); \
    AddDumpFunction(OsciHR, PSDAvrgTypeGet); \
    AddDumpFunction(OsciHR, PSDAvrgCountSet, nano_int); \
    AddDumpFunction(OsciHR, PSDAvrgCountGet); \
    AddDumpFunction(OsciHR, PSDAvrgRestart); \
    AddDumpFunction(OsciHR, PSDDataGet, nano_unsigned_int16, nano_float64);

#define AddDumpOsci1TFunctions \
    AddDumpFunction(Osci1T, ChSet, nano_int); \
    AddDumpFunction(Osci1T, ChGet); \
    AddDumpFunction(Osci1T, TimebaseSet, nano_int); \
    AddDumpFunction(Osci1T, TimebaseGet); \
    AddDumpFunction(Osci1T, TrigSet, nano_unsigned_int16, nano_unsigned_int16, nano_float64, nano_float64); \
    AddDumpFunction(Osci1T, TrigGet); \
    AddDumpFunction(Osci1T, Run); \
    AddDumpFunction(Osci1T, DataGet, nano_unsigned_int16);

#define AddDumpOsci2TFunctions \
    AddDumpFunction(Osci2T, ChsSet, nano_int, nano_int); \
    AddDumpFunction(Osci2T, ChsGet); \
    AddDumpFunction(Osci2T, TimebaseSet, nano_unsigned_int16); \
    AddDumpFunction(Osci2T, TimebaseGet); \
    AddDumpFunction(Osci2T, OversamplSet, nano_unsigned_int16); \
    AddDumpFunction(Osci2T, OversamplGet); \
    AddDumpFunction(Osci2T, TrigSet, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16, nano_float64, nano_float64, nano_float64); \
    AddDumpFunction(Osci2T, TrigGet); \
    AddDumpFunction(Osci2T, Run); \
    AddDumpFunction(Osci2T, DataGet, nano_unsigned_int16);

#define AddDumpSignalChartFunctions \
    AddDumpFunction(SignalChart, Open); \
    AddDumpFunction(SignalChart, ChsSet, nano_int, nano_int); \
    AddDumpFunction(SignalChart, ChsGet);

#define AddDumpSpectrumAnlzrFunctions \
    AddDumpFunction(SpectrumAnlzr, ChSet, nano_int, nano_int); \
    AddDumpFunction(SpectrumAnlzr, ChGet, nano_int); \
    AddDumpFunction(SpectrumAnlzr, FreqRangeSet, nano_int, nano_int); \
    AddDumpFunction(SpectrumAnlzr, FreqRangeGet, nano_int); \
    AddDumpFunction(SpectrumAnlzr, FreqResSet, nano_int, nano_unsigned_int16); \
    AddDumpFunction(SpectrumAnlzr, FreqResGet, nano_int); \
    AddDumpFunction(SpectrumAnlzr, FFTWindowSet, nano_int, nano_unsigned_int16); \
    AddDumpFunction(SpectrumAnlzr, FFTWindowGet, nano_int); \
    AddDumpFunction(SpectrumAnlzr, AveragSet, nano_int, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int32); \
    AddDumpFunction(SpectrumAnlzr, AveragGet, nano_int); \
    AddDumpFunction(SpectrumAnlzr, ACCouplingSet, nano_int, nano_unsigned_int32); \
    AddDumpFunction(SpectrumAnlzr, ACCouplingGet, nano_int); \
    AddDumpFunction(SpectrumAnlzr, CursorPosSet, nano_int, nano_unsigned_int16, nano_float64, nano_float64); \
    AddDumpFunction(SpectrumAnlzr, CursorPosGet, nano_int, nano_unsigned_int16); \
    AddDumpFunction(SpectrumAnlzr, BandRMSGet, nano_int); \
    AddDumpFunction(SpectrumAnlzr, DCGet, nano_int); \
    AddDumpFunction(SpectrumAnlzr, Run, nano_int); \
    AddDumpFunction(SpectrumAnlzr, DataGet, nano_int);

#define AddDumpFunGen1ChFunctions \
    AddDumpFunction(FunGen1Ch, Start, nano_int); \
    AddDumpFunction(FunGen1Ch, Stop); \
    AddDumpFunction(FunGen1Ch, StatusGet); \
    AddDumpFunction(FunGen1Ch, PropsSet, nano_float32, nano_float32, nano_unsigned_int16, nano_unsigned_int16); \
    AddDumpFunction(FunGen1Ch, PropsGet); \
    AddDumpFunction(FunGen1Ch, IdleSet, nano_float32); \
    AddDumpFunction(FunGen1Ch, IdleGet);

#define AddDumpFunGen2ChFunctions \
    AddDumpFunction(FunGen2Ch, Start, nano_int); \
    AddDumpFunction(FunGen2Ch, Stop); \
    AddDumpFunction(FunGen2Ch, StatusGet); \
    AddDumpFunction(FunGen2Ch, IdleSet, nano_int, nano_float32); \
    AddDumpFunction(FunGen2Ch, IdleGet, nano_int); \
    AddDumpFunction(FunGen2Ch, OnOffSet, nano_int, nano_unsigned_int32); \
    AddDumpFunction(FunGen2Ch, OnOffGet, nano_int); \
    AddDumpFunction(FunGen2Ch, SignalSet, nano_int, nano_int); \
    AddDumpFunction(FunGen2Ch, SignalGet, nano_int); \
    AddDumpFunction(FunGen2Ch, PropsSet, nano_int, nano_float32, nano_float32, nano_unsigned_int16, nano_unsigned_int16, nano_unsigned_int16); \
    AddDumpFunction(FunGen2Ch, PropsGet, nano_int); \
    AddDumpFunction(FunGen2Ch, WaveformSet, nano_int, nano_unsigned_int16); \
    AddDumpFunction(FunGen2Ch, WaveformGet, nano_int);

#define AddDumpUtilFunctions \
    AddDumpFunction(Util, SessionPathGet); \
    AddDumpFunction(Util, SettingsLoad, nano_int, nano_string, nano_unsigned_int32); \
    AddDumpFunction(Util, SettingsSave, nano_int, nano_string, nano_unsigned_int32); \
    AddDumpFunction(Util, LayoutLoad, nano_int, nano_string, nano_unsigned_int32); \
    AddDumpFunction(Util, LayoutSave, nano_int, nano_string, nano_unsigned_int32); \
    AddDumpFunction(Util, Lock); \
    AddDumpFunction(Util, UnLock); \
    AddDumpFunction(Util, RTFreqSet, nano_float32); \
    AddDumpFunction(Util, RTFreqGet); \
    AddDumpFunction(Util, AcqPeriodSet, nano_float32); \
    AddDumpFunction(Util, AcqPeriodGet); \
    AddDumpFunction(Util, RTOversamplSet, nano_int); \
    AddDumpFunction(Util, RTOversamplGet); \
    AddDumpFunction(Util, Quit, nano_unsigned_int32, nano_int, nano_string, nano_int, nano_string, nano_unsigned_int32);

#define AddWholeFunctions \
    AddBiasFunctions; \
    AddBiasSwpFunctions; \
    AddBiasSpectrFunctions; \
    AddKelvinCtrlFunctions; \
    AddCPDCompFunctions; \
    AddCurrentFunctions; \
    AddZCtrlFunctions; \
    AddSafeTipFunctions; \
    AddAutoApproachFunctions; \
    AddZSpectrFunctions; \
    AddPiezoFunctions; \
    AddScanFunctions; \
    AddFolMeFunctions; \
    AddTipRecFunctions; \
    AddPatternFunctions; \
    AddMarksFunctions; \
    AddTipShaperFunctions; \
    AddMotorFunctions; \
    AddGenSwpFunctions; \
    AddGenPICtrlFunctions; \
    AddAtomTrackFunctions; \
    AddLockInFunctions; \
    AddLockInFreqSwpFunctions; \
    AddPLLFunctions; \
    AddPLLQCtrlFunctions; \
    AddPLLFreqSwpFunctions; \
    AddPLLPhasSwpFunctions; \
    AddPLLSignalAnlzrFunctions; \
    AddPLLZoomFFTFunctions; \
    AddOCSyncFunctions; \
    AddScriptFunctions; \
    AddInterfFunctions; \
    AddLaserFunctions; \
    AddBeamDeflFunctions; \
    AddSignalsFunctions; \
    AddUserInFunctions; \
    AddUserOutFunctions; \
    AddDigLinesFunctions; \
    AddDataLogFunctions; \
    AddTCPLogFunctions; \
    AddOsciHRFunctions; \
    AddOsci1TFunctions; \
    AddOsci2TFunctions; \
    AddSignalChartFunctions; \
    AddSpectrumAnlzrFunctions; \
    AddFunGen1ChFunctions; \
    AddFunGen2ChFunctions; \
    AddUtilFunctions; \
    AddDumpBiasFunctions; \
    AddDumpBiasSwpFunctions; \
    AddDumpBiasSpectrFunctions; \
    AddDumpKelvinCtrlFunctions; \
    AddDumpCPDCompFunctions; \
    AddDumpCurrentFunctions; \
    AddDumpZCtrlFunctions; \
    AddDumpSafeTipFunctions; \
    AddDumpAutoApproachFunctions; \
    AddDumpZSpectrFunctions; \
    AddDumpPiezoFunctions; \
    AddDumpScanFunctions; \
    AddDumpFolMeFunctions; \
    AddDumpTipRecFunctions; \
    AddDumpPatternFunctions; \
    AddDumpMarksFunctions; \
    AddDumpTipShaperFunctions; \
    AddDumpMotorFunctions; \
    AddDumpGenSwpFunctions; \
    AddDumpGenPICtrlFunctions; \
    AddDumpAtomTrackFunctions; \
    AddDumpLockInFunctions; \
    AddDumpLockInFreqSwpFunctions; \
    AddDumpPLLFunctions; \
    AddDumpPLLQCtrlFunctions; \
    AddDumpPLLFreqSwpFunctions; \
    AddDumpPLLPhasSwpFunctions; \
    AddDumpPLLSignalAnlzrFunctions; \
    AddDumpPLLZoomFFTFunctions; \
    AddDumpOCSyncFunctions; \
    AddDumpScriptFunctions; \
    AddDumpInterfFunctions; \
    AddDumpLaserFunctions; \
    AddDumpBeamDeflFunctions; \
    AddDumpSignalsFunctions; \
    AddDumpUserInFunctions; \
    AddDumpUserOutFunctions; \
    AddDumpDigLinesFunctions; \
    AddDumpDataLogFunctions; \
    AddDumpTCPLogFunctions; \
    AddDumpOsciHRFunctions; \
    AddDumpOsci1TFunctions; \
    AddDumpOsci2TFunctions; \
    AddDumpSignalChartFunctions; \
    AddDumpSpectrumAnlzrFunctions; \
    AddDumpFunGen1ChFunctions; \
    AddDumpFunGen2ChFunctions; \
    AddDumpUtilFunctions;
    
#endif // MACRO_H
