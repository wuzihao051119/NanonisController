// Copyright (c) 2025 Zihao Wu
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef MACRO_H
#define MACRO_H

#include <vector>
#include <string>

#define ResponseBackTrue (nano_unsigned_int16)1
#define ResponseBackFalse (nano_unsigned_int16)0

#define AddCommand(Module, Func) \
    m_command.emplace(#Module "." #Func, std::bind(&Function::Module##Func, &m_function, std::placeholders::_1));
#define AddFunction(Module, Func, ...) \
    inline void Module##Func(std::vector<std::string> &args) { \
        appendArgs<__VA_ARGS__ __VA_OPT__(,) void>(m_os, args); \
    }

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
    AddCommand(PDComp, Open); \
    AddCommand(PDComp, Close); \
    AddCommand(PDComp, ParamsSet); \
    AddCommand(PDComp, ParamsGet); \
    AddCommand(PDComp, DataGet); \
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

#define AddPDCompFunctions \
    AddFunction(PDComp, Open); \
    AddFunction(PDComp, Close); \
    AddFunction(PDComp, ParamsSet, nano_float32, nano_float32, nano_int); \
    AddFunction(PDComp, ParamsGet); \
    AddFunction(PDComp, DataGet);

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

#define AddWholeFunctions \
    AddBiasFunctions; \
    AddBiasSwpFunctions; \
    AddBiasSpectrFunctions; \
    AddKelvinCtrlFunctions; \
    AddPDCompFunctions; \
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
    AddUtilFunctions;
    
#endif // MACRO_H
