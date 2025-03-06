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
    AddCommand(BiasSwp, LimitsSet);
    // AddCommand(BiasSpectr, PropsGet); \
    // AddCommand(BiasSpectr, AdvPropsSet); \
    // AddCommand(BiasSpectr, AdvPropsGet); \
    // AddCommand(BiasSpectr, LimitsSet); \
    // AddCommand(BiasSpectr, LimitsGet); \
    // AddCommand(BiasSpectr, TimingSet); \
    // AddCommand(BiasSpectr, TimingGet); \
    // AddCommand(BiasSpectr, TTLSyncSet); \
    // AddCommand(BiasSpectr, TTLSyncGet); \
    // AddCommand(BiasSpectr, AltZCtrlSet); \
    // AddCommand(BiasSpectr, AltZCtrlGet); \
    // AddCommand(BiasSpectr, MLSLockinPerSegSet); \
    // AddCommand(BiasSpectr, MLSLockinPerSegGet); \
    // AddCommand(BiasSpectr, MLSModeSet); \
    // AddCommand(BiasSpectr, MLSModeGet); \
    // AddCommand(BiasSpectr, MLSValsSet); \
    // AddCommand(BiasSpectr, MLSValsGet); \
    // AddCommand(KelvinCtrl, CtrlOnOffSet); \
    // AddCommand(KelvinCtrl, CtrlOnOffGet); \
    // AddCommand(KelvinCtrl, SetpntSet); \
    // AddCommand(KelvinCtrl, SetpntGet); \
    // AddCommand(KelvinCtrl, GainSet); \
    // AddCommand(KelvinCtrl, GainGet); \
    // AddCommand(KelvinCtrl, ModParamsSet); \
    // AddCommand(KelvinCtrl, ModParamsGet); \
    // AddCommand(KelvinCtrl, ModOnOffSet); \
    // AddCommand(KelvinCtrl, ModOnOffGet); \
    // AddCommand(KelvinCtrl, CtrlSignalSet); \
    // AddCommand(KelvinCtrl, CtrlSignalGet); \
    // AddCommand(KelvinCtrl, AmpGet); \
    // AddCommand(KelvinCtrl, BiasLimitsSet); \
    // AddCommand(KelvinCtrl, BiasLimitsGet); \
    // AddCommand(PDComp, Open); \
    // AddCommand(PDComp, Close); \
    // AddCommand(PDComp, ParamsSet); \
    // AddCommand(PDComp, ParamsGet); \
    // AddCommand(PDComp, DataGet); \
    // AddCommand(Current, Get); \
    // AddCommand(Current, Get100); \
    // AddCommand(Current, BEEMGet); \
    // AddCommand(Current, GainSet); \
    // AddCommand(Current, GainsGet); \
    // AddCommand(Current, CalibrSet); \
    // AddCommand(Current, CalibrGet); \
    // AddCommand(ZCtrl, ZPosSet); \
    // AddCommand(ZCtrl, ZPosGet); \
    // AddCommand(ZCtrl, OnOffSet); \
    // AddCommand(ZCtrl, OnOffGet); \
    // AddCommand(ZCtrl, SetpntSet); \
    // AddCommand(ZCtrl, SetpntGet); \
    // AddCommand(ZCtrl, GainSet); \
    // AddCommand(ZCtrl, GainGet); \
    // AddCommand(ZCtrl, SwitchOffDelaySet); \
    // AddCommand(ZCtrl, SwitchOffDelayGet); \
    // AddCommand(ZCtrl, TipLiftSet); \
    // AddCommand(ZCtrl, TipLiftGet); \
    // AddCommand(ZCtrl, Home); \
    // AddCommand(ZCtrl, HomePropsSet); \
    // AddCommand(ZCtrl, HomePropsGet); \
    // AddCommand(ZCtrl, ActiveCtrlSet); \
    // AddCommand(ZCtrl, CtrlListGet); \
    // AddCommand(ZCtrl, Withdraw); \
    // AddCommand(ZCtrl, WithdrawRateSet); \
    // AddCommand(ZCtrl, WithdrawRateGet); \
    // AddCommand(ZCtrl, LimitsEnabledSet); \
    // AddCommand(ZCtrl, LimitsEnabledGet); \
    // AddCommand(ZCtrl, LimitsSet); \
    // AddCommand(ZCtrl, LimitsGet); \
    // AddCommand(ZCtrl, StatusGet); \
    // AddCommand(SafeTip, OnOffSet); \
    // AddCommand(SafeTip, OnOffGet); \
    // AddCommand(SafeTip, SignalGet); \
    // AddCommand(SafeTip, PropsSet); \
    // AddCommand(SafeTip, PropsGet); \
    // AddCommand(AutoApproach, Open); \
    // AddCommand(AutoApproach, OnOffSet); \
    // AddCommand(AutoApproach, OnOffGet); \
    // AddCommand(ZSpectr, Open); \
    // AddCommand(ZSpectr, Start); \
    // AddCommand(ZSpectr, Stop); \
    // AddCommand(ZSpectr, StatusGet); \
    // AddCommand(ZSpectr, ChsSet); \
    // AddCommand(ZSpectr, ChsGet); \
    // AddCommand(ZSpectr, PropsSet); \
    // AddCommand(ZSpectr, PropsGet); \
    // AddCommand(ZSpectr, AdvPropsSet); \
    // AddCommand(ZSpectr, AdvPropsGet); \
    // AddCommand(ZSpectr, RangeSet); \
    // AddCommand(ZSpectr, RangeGet); \
    // AddCommand(ZSpectr, TimingSet); \
    // AddCommand(ZSpectr, TimingGet); \
    // AddCommand(ZSpectr, RetractDelaySet); \
    // AddCommand(ZSpectr, RetractDelayGet); \
    // AddCommand(ZSpectr, RetractSet); \
    // AddCommand(ZSpectr, RetractGet); \
    // AddCommand(ZSpectr, Retract2ndSet); \
    // AddCommand(ZSpectr, Retract2ndGet); \
    // AddCommand(Piezo, TiltSet); \
    // AddCommand(Piezo, TiltGet); \
    // AddCommand(Piezo, RangeSet); \
    // AddCommand(Piezo, RangeGet); \
    // AddCommand(Piezo, SensSet); \
    // AddCommand(Piezo, SensGet); \
    // AddCommand(Piezo, DriftCompSet); \
    // AddCommand(Piezo, DriftCompGet); \
    // AddCommand(Piezo, CalibrGet); \
    // AddCommand(Piezo, HVAInfoGet); \
    // AddCommand(Piezo, HVAStatusLEDGet); \
    // AddCommand(Scan, Action); \
    // AddCommand(Scan, StatusGet); \
    // AddCommand(Scan, WaitEndOfScan); \
    // AddCommand(Scan, FrameSet); \
    // AddCommand(Scan, FrameGet); \
    // AddCommand(Scan, BufferSet); \
    // AddCommand(Scan, BufferGet); \
    // AddCommand(Scan, PropsSet); \
    // AddCommand(Scan, PropsGet); \
    // AddCommand(Scan, SpeedSet); \
    // AddCommand(Scan, SpeedGet); \
    // AddCommand(Scan, FrameDataGrab); \
    // AddCommand(FolMe, XYPosSet); \
    // AddCommand(FolMe, XYPosGet); \
    // AddCommand(FolMe, SpeedSet); \
    // AddCommand(FolMe, SpeedGet); \
    // AddCommand(FolMe, OversamplSet); \
    // AddCommand(FolMe, OversamplGet); \
    // AddCommand(FolMe, Stop); \
    // AddCommand(FolMe, PSOnOffGet); \
    // AddCommand(FolMe, PSOnOffSet); \
    // AddCommand(FolMe, PSExpGet); \
    // AddCommand(FolMe, PSExpSet); \
    // AddCommand(FolMe, PSPropsGet); \
    // AddCommand(FolMe, PSPropsSet); \
    // AddCommand(TipRec, BufferSizeSet); \
    // AddCommand(TipRec, BufferSizeGet); \
    // AddCommand(TipRec, BufferClear); \
    // AddCommand(TipRec, DataGet); \
    // AddCommand(TipRec, DataSave); \
    // AddCommand(Pattern, ExpOpen); \
    // AddCommand(Pattern, ExpStart); \
    // AddCommand(Pattern, ExpPause); \
    // AddCommand(Pattern, ExpStop); \
    // AddCommand(Pattern, ExpStatusGet); \
    // AddCommand(Pattern, GridSet); \
    // AddCommand(Pattern, GridGet); \
    // AddCommand(Pattern, LineSet); \
    // AddCommand(Pattern, LineGet); \
    // AddCommand(Pattern, CloudSet); \
    // AddCommand(Pattern, CloudGet); \
    // AddCommand(Pattern, PropsSet); \
    // AddCommand(Pattern, PropsGet); \
    // AddCommand(Marks, PointDraw); \
    // AddCommand(Marks, PointsDraw); \
    // AddCommand(Marks, LineDraw); \
    // AddCommand(Marks, LinesDraw); \
    // AddCommand(Marks, PointsErase); \
    // AddCommand(Marks, LinesErase); \
    // AddCommand(Marks, PointsVisibleSet); \
    // AddCommand(Marks, LinesVisibleSet); \
    // AddCommand(Marks, PointsGet); \
    // AddCommand(Marks, LinesGet); \
    // AddCommand(TipShaper, Start); \
    // AddCommand(TipShaper, PropsSet); \
    // AddCommand(TipShaper, PropsGet); \
    // AddCommand(Motor, StartMove); \
    // AddCommand(Motor, StartClosedLoop); \
    // AddCommand(Motor, StopMove); \
    // AddCommand(Motor, PosGet); \
    // AddCommand(Motor, StepCounterGet); \
    // AddCommand(Motor, FreqAmpGet); \
    // AddCommand(Motor, FreqAmpSet); \
    // AddCommand(GenSwp, AcqChsSet); \
    // AddCommand(GenSwp, AcqChsGet); \
    // AddCommand(GenSwp, SwpSignalSet); \
    // AddCommand(GenSwp, SwpSignalGet); \
    // AddCommand(GenSwp, LimitsSet); \
    // AddCommand(GenSwp, LimitsGet); \
    // AddCommand(GenSwp, PropsSet); \
    // AddCommand(GenSwp, PropsGet); \
    // AddCommand(GenSwp, Start); \
    // AddCommand(GenSwp, Stop); \
    // AddCommand(GenSwp, Open); \
    // AddCommand(GenPICtrl, OnOffSet); \
    // AddCommand(GenPICtrl, OnOffGet); \
    // AddCommand(GenPICtrl, AOValSet); \
    // AddCommand(GenPICtrl, AOValGet); \
    // AddCommand(GenPICtrl, AOPropsSet); \
    // AddCommand(GenPICtrl, AOPropsGet); \
    // AddCommand(GenPICtrl, ModChSet); \
    // AddCommand(GenPICtrl, ModChGet); \
    // AddCommand(GenPICtrl, DemodChSet); \
    // AddCommand(GenPICtrl, DemodChGet); \
    // AddCommand(GenPICtrl, PropsSet); \
    // AddCommand(GenPICtrl, PropsGet); \
    // AddCommand(AtomTrack, CtrlSet); \
    // AddCommand(AtomTrack, StatusGet); \
    // AddCommand(AtomTrack, PropsSet); \
    // AddCommand(AtomTrack, PropsGet); \
    // AddCommand(AtomTrack, QuickCompStart); \
    // AddCommand(AtomTrack, DriftComp); \
    // AddCommand(LockIn, ModOnOffSet); \
    // AddCommand(LockIn, ModOnOffGet); \
    // AddCommand(LockIn, ModSignalSet); \
    // AddCommand(LockIn, ModSignalGet); \
    // AddCommand(LockIn, ModPhasRegSet); \
    // AddCommand(LockIn, ModPhasRegGet); \
    // AddCommand(LockIn, ModHarmonicSet); \
    // AddCommand(LockIn, ModHarmonicGet); \
    // AddCommand(LockIn, ModPhasSet); \
    // AddCommand(LockIn, ModPhasGet); \
    // AddCommand(LockIn, ModAmpSet); \
    // AddCommand(LockIn, ModAmpGet); \
    // AddCommand(LockIn, ModPhasFreqSet); \
    // AddCommand(LockIn, ModPhasFreqGet); \
    // AddCommand(LockIn, DemodSignalSet); \
    // AddCommand(LockIn, DemodSignalGet); \
    // AddCommand(LockIn, DemodHarmonicSet); \
    // AddCommand(LockIn, DemodHarmonicGet); \
    // AddCommand(LockIn, DemodHPFilterSet); \
    // AddCommand(LockIn, DemodHPFilterGet); \
    // AddCommand(LockIn, DemodLPFilterSet); \
    // AddCommand(LockIn, DemodLPFilterGet); \
    // AddCommand(LockIn, DemodPhasRegSet); \
    // AddCommand(LockIn, DemodPhasRegGet); \
    // AddCommand(LockIn, DemodPhasSet); \
    // AddCommand(LockIn, DemodPhasGet); \
    // AddCommand(LockIn, DemodSyncFilterSet); \
    // AddCommand(LockIn, DemodSyncFilterGet); \
    // AddCommand(LockIn, DemodRTSignalsSet); \
    // AddCommand(LockIn, DemodRTSignalsGet); \
    // AddCommand(LockInFreqSwp, Open); \
    // AddCommand(LockInFreqSwp, Start); \
    // AddCommand(LockInFreqSwp, SignalSet); \
    // AddCommand(LockInFreqSwp, SignalGet); \
    // AddCommand(LockInFreqSwp, LimitsSet); \
    // AddCommand(LockInFreqSwp, LimitsGet); \
    // AddCommand(LockInFreqSwp, PropsSet); \
    // AddCommand(LockInFreqSwp, PropsGet); \
    // AddCommand(PLL, InpCalibrSet); \
    // AddCommand(PLL, InpCalibrGet); \
    // AddCommand(PLL, InpRangeSet); \
    // AddCommand(PLL, InpRangeGet); \
    // AddCommand(PLL, InpPropsSet); \
    // AddCommand(PLL, InpPropsGet); \
    // AddCommand(PLL, AddOnOffSet); \
    // AddCommand(PLL, AddOnOffGet); \
    // AddCommand(PLL, OutOnOffSet); \
    // AddCommand(PLL, OutOnOffGet); \
    // AddCommand(PLL, ExcRangeSet); \
    // AddCommand(PLL, ExcRangeGet); \
    // AddCommand(PLL, ExcitationSet); \
    // AddCommand(PLL, ExcitationGet); \
    // AddCommand(PLL, AmpCtrlSetpntSet); \
    // AddCommand(PLL, AmpCtrlSetpntGet); \
    // AddCommand(PLL, AmpCtrlOnOffSet); \
    // AddCommand(PLL, AmpCtrlOnOffGet); \
    // AddCommand(PLL, AmpCtrlGainSet); \
    // AddCommand(PLL, AmpCtrlGainGet); \
    // AddCommand(PLL, AmpCtrlBandwidthSet); \
    // AddCommand(PLL, AmpCtrlBandwidthGet); \
    // AddCommand(PLL, PhasCtrlOnOffSet); \
    // AddCommand(PLL, PhasCtrlOnOffGet); \
    // AddCommand(PLL, PhasCtrlGainSet); \
    // AddCommand(PLL, PhasCtrlGainGet); \
    // AddCommand(PLL, PhasCtrlBandwidthSet); \
    // AddCommand(PLL, PhasCtrlBandwidthGet); \
    // AddCommand(PLL, FreqRangeSet); \
    // AddCommand(PLL, FreqRangeGet); \
    // AddCommand(PLL, CenterFreqSet); \
    // AddCommand(PLL, CenterFreqGet); \
    // AddCommand(PLL, FreqShiftSet); \
    // AddCommand(PLL, FreqShiftGet); \
    // AddCommand(PLL, FreqShiftAutoCenter); \
    // AddCommand(PLL, FreqExcOverwriteSet); \
    // AddCommand(PLL, FreqExcOverwriteGet); \
    // AddCommand(PLL, DemodInputSet); \
    // AddCommand(PLL, DemodInputGet); \
    // AddCommand(PLL, DemodHarmonicSet); \
    // AddCommand(PLL, DemodHarmonicGet); \
    // AddCommand(PLL, DemodPhasRefSet); \
    // AddCommand(PLL, DemodPhasRefGet); \
    // AddCommand(PLL, DemodFilterSet); \
    // AddCommand(PLL, DemodFilterGet); \
    // AddCommand(PLLQCtrl, AccessRequest); \
    // AddCommand(PLLQCtrl, AccessGet); \
    // AddCommand(PLLQCtrl, OnOffSet); \
    // AddCommand(PLLQCtrl, OnOffGet); \
    // AddCommand(PLLQCtrl, QGainSet); \
    // AddCommand(PLLQCtrl, QGainGet); \
    // AddCommand(PLLQCtrl, PhaseSet); \
    // AddCommand(PLLQCtrl, PhaseGet); \
    // AddCommand(PLLFreqSwp, Open); \
    // AddCommand(PLLFreqSwp, ParamsSet); \
    // AddCommand(PLLFreqSwp, ParamsGet); \
    // AddCommand(PLLFreqSwp, Start); \
    // AddCommand(PLLFreqSwp, Stop); \
    // AddCommand(PLLPhasSwp, Start); \
    // AddCommand(PLLPhasSwp, Stop); \
    // AddCommand(PLLSignalAnlzr, Open); \
    // AddCommand(PLLSignalAnlzr, ChSet); \
    // AddCommand(PLLSignalAnlzr, ChGet); \
    // AddCommand(PLLSignalAnlzr, TimebaseSet); \
    // AddCommand(PLLSignalAnlzr, TimebaseGet); \
    // AddCommand(PLLSignalAnlzr, TrigAuto); \
    // AddCommand(PLLSignalAnlzr, TrigRearm); \
    // AddCommand(PLLSignalAnlzr, TrigSet); \
    // AddCommand(PLLSignalAnlzr, TrigGet); \
    // AddCommand(PLLSignalAnlzr, OsciDataGet); \
    // AddCommand(PLLSignalAnlzr, FFTPropsSet); \
    // AddCommand(PLLSignalAnlzr, FFTPropsGet); \
    // AddCommand(PLLSignalAnlzr, FFTAvgRestart); \
    // AddCommand(PLLSignalAnlzr, FFTDataGet); \
    // AddCommand(PLLZoomFFT, Open); \
    // AddCommand(PLLZoomFFT, ChSet); \
    // AddCommand(PLLZoomFFT, ChGet); \
    // AddCommand(PLLZoomFFT, AvgRestart); \
    // AddCommand(PLLZoomFFT, PropsSet); \
    // AddCommand(PLLZoomFFT, PropsGet); \
    // AddCommand(PLLZoomFFT, DataGet); \
    // AddCommand(OCSync, AnglesSet); \
    // AddCommand(OCSync, AnglesGet); \
    // AddCommand(OCSync, LinkAnglesSet); \
    // AddCommand(OCSync, LinkAnglesGet); \
    // AddCommand(Script, Load); \
    // AddCommand(Script, Save); \
    // AddCommand(Script, Deploy); \
    // AddCommand(Script, Undeploy); \
    // AddCommand(Script, Run); \
    // AddCommand(Script, Stop); \
    // AddCommand(Script, ChsGet); \
    // AddCommand(Script, ChsSet); \
    // AddCommand(Script, DataGet); \
    // AddCommand(Script, Autosave); \
    // AddCommand(Interf, CtrlOnOffSet); \
    // AddCommand(Interf, CtrlOnOffGet); \
    // AddCommand(Interf, CtrlPropsSet); \
    // AddCommand(Interf, CtrlPropsGet); \
    // AddCommand(Interf, WPiezoSet); \
    // AddCommand(Interf, WPiezoGet); \
    // AddCommand(Interf, ValGet); \
    // AddCommand(Interf, CtrlCalibrOpen); \
    // AddCommand(Interf, CtrlReset); \
    // AddCommand(Interf, CtrlNullDefl); \
    // AddCommand(Laser, OnOffSet); \
    // AddCommand(Laser, OnOffGet); \
    // AddCommand(Laser, PropsSet); \
    // AddCommand(Laser, PropsGet); \
    // AddCommand(Laser, PowerGet); \
    // AddCommand(BeamDefl, HorConfigSet); \
    // AddCommand(BeamDefl, HorConfigGet); \
    // AddCommand(BeamDefl, VerConfigSet); \
    // AddCommand(BeamDefl, VerConfigGet); \
    // AddCommand(BeamDefl, IntConfigSet); \
    // AddCommand(BeamDefl, IntConfigGet); \
    // AddCommand(BeamDefl, AutoOffset); \
    // AddCommand(Signals, NamesGet); \
    // AddCommand(Signals, InSlotSet); \
    // AddCommand(Signals, InSlotsGet); \
    // AddCommand(Signals, CalibrGet); \
    // AddCommand(Signals, RangeGet); \
    // AddCommand(Signals, ValGet); \
    // AddCommand(Signals, ValsGet); \
    // AddCommand(Signals, MeasNamesGet); \
    // AddCommand(Signals, AddRTGet); \
    // AddCommand(Signals, AddRTSet); \
    // AddCommand(UserIn, CalibrSet); \
    // AddCommand(UserOut, ModeSet); \
    // AddCommand(UserOut, ModeGet); \
    // AddCommand(UserOut, MonitorChSet); \
    // AddCommand(UserOut, MonitorChGet); \
    // AddCommand(UserOut, ValSet); \
    // AddCommand(UserOut, CalibrSet); \
    // AddCommand(UserOut, CalcSignalNameSet); \
    // AddCommand(UserOut, CalcSignalNameGet); \
    // AddCommand(UserOut, CalcSignalConfigSet); \
    // AddCommand(UserOut, CalcSignalConfigGet); \
    // AddCommand(UserOut, LimitsSet); \
    // AddCommand(UserOut, LimitsGet); \
    // AddCommand(DigLines, PropsSet); \
    // AddCommand(DigLines, OutStatusSet); \
    // AddCommand(DigLines, TTLValGet); \
    // AddCommand(DigLines, Pulse); \
    // AddCommand(DataLog, Open); \
    // AddCommand(DataLog, Start); \
    // AddCommand(DataLog, Stop); \
    // AddCommand(DataLog, StatusGet); \
    // AddCommand(DataLog, ChsSet); \
    // AddCommand(DataLog, ChsGet); \
    // AddCommand(DataLog, PropsSet); \
    // AddCommand(DataLog, PropsGet); \
    // AddCommand(TCPLog, Start); \
    // AddCommand(TCPLog, Stop); \
    // AddCommand(TCPLog, ChsSet); \
    // AddCommand(TCPLog, OversamplSet); \
    // AddCommand(TCPLog, StatusGet); \
    // AddCommand(OsciHR, ChSet); \
    // AddCommand(OsciHR, ChGet); \
    // AddCommand(OsciHR, OversamplSet); \
    // AddCommand(OsciHR, OversamplGet); \
    // AddCommand(OsciHR, CalibrModeSet); \
    // AddCommand(OsciHR, CalibrModeGet); \
    // AddCommand(OsciHR, SamplesSet); \
    // AddCommand(OsciHR, SamplesGet); \
    // AddCommand(OsciHR, PreTrigSet); \
    // AddCommand(OsciHR, PreTrigGet); \
    // AddCommand(OsciHR, Run); \
    // AddCommand(OsciHR, OsciDataGet); \
    // AddCommand(OsciHR, TrigModeSet); \
    // AddCommand(OsciHR, TrigModeGet); \
    // AddCommand(OsciHR, TrigLevChSet); \
    // AddCommand(OsciHR, TrigLevChGet); \
    // AddCommand(OsciHR, TrigLevValSet); \
    // AddCommand(OsciHR, TrigLevValGet); \
    // AddCommand(OsciHR, TrigLevHystSet); \
    // AddCommand(OsciHR, TrigLevHystGet); \
    // AddCommand(OsciHR, TrigLevSlopeSet); \
    // AddCommand(OsciHR, TrigLevSlopeGet); \
    // AddCommand(OsciHR, TrigDigChSet); \
    // AddCommand(OsciHR, TrigDigChGet); \
    // AddCommand(OsciHR, TrigArmModeSet); \
    // AddCommand(OsciHR, TrigArmModeGet); \
    // AddCommand(OsciHR, TrigDigSlopeSet); \
    // AddCommand(OsciHR, TrigDigSlopeGet); \
    // AddCommand(OsciHR, TrigRearm); \
    // AddCommand(OsciHR, PSDShow); \
    // AddCommand(OsciHR, PSDWeightSet); \
    // AddCommand(OsciHR, PSDWeightGet); \
    // AddCommand(OsciHR, PSDWindowSet); \
    // AddCommand(OsciHR, PSDWindowGet); \
    // AddCommand(OsciHR, PSDAvrgTypeSet); \
    // AddCommand(OsciHR, PSDAvrgTypeGet); \
    // AddCommand(OsciHR, PSDAvrgCountSet); \
    // AddCommand(OsciHR, PSDAvrgCountGet); \
    // AddCommand(OsciHR, PSDAvrgRestart); \
    // AddCommand(OsciHR, PSDDataGet); \
    // AddCommand(Osci1T, ChSet); \
    // AddCommand(Osci1T, ChGet); \
    // AddCommand(Osci1T, TimebaseSet); \
    // AddCommand(Osci1T, TimebaseGet); \
    // AddCommand(Osci1T, TrigSet); \
    // AddCommand(Osci1T, TrigGet); \
    // AddCommand(Osci1T, Run); \
    // AddCommand(Osci1T, DataGet); \
    // AddCommand(Osci2T, ChsSet); \
    // AddCommand(Osci2T, ChsGet); \
    // AddCommand(Osci2T, TimebaseSet); \
    // AddCommand(Osci2T, TimebaseGet); \
    // AddCommand(Osci2T, OversamplSet); \
    // AddCommand(Osci2T, OversamplGet); \
    // AddCommand(Osci2T, TrigSet); \
    // AddCommand(Osci2T, TrigGet); \
    // AddCommand(Osci2T, Run); \
    // AddCommand(Osci2T, DataGet); \
    // AddCommand(SignalChart, Open); \
    // AddCommand(SignalChart, ChsSet); \
    // AddCommand(SignalChart, ChsGet); \
    // AddCommand(SpectrumAnlzr, ChSet); \
    // AddCommand(SpectrumAnlzr, ChGet); \
    // AddCommand(SpectrumAnlzr, FreqRangeSet); \
    // AddCommand(SpectrumAnlzr, FreqRangeGet); \
    // AddCommand(SpectrumAnlzr, FreqResSet); \
    // AddCommand(SpectrumAnlzr, FreqResGet); \
    // AddCommand(SpectrumAnlzr, FFTWindowSet); \
    // AddCommand(SpectrumAnlzr, FFTWindowGet); \
    // AddCommand(SpectrumAnlzr, AveragSet); \
    // AddCommand(SpectrumAnlzr, AveragGet); \
    // AddCommand(SpectrumAnlzr, ACCouplingSet); \
    // AddCommand(SpectrumAnlzr, ACCouplingGet); \
    // AddCommand(SpectrumAnlzr, CursorPosSet); \
    // AddCommand(SpectrumAnlzr, CursorPosGet); \
    // AddCommand(SpectrumAnlzr, BandRMSGet); \
    // AddCommand(SpectrumAnlzr, DCGet); \
    // AddCommand(SpectrumAnlzr, Run); \
    // AddCommand(SpectrumAnlzr, DataGet); \
    // AddCommand(FunGen1Ch, Start); \
    // AddCommand(FunGen1Ch, Stop); \
    // AddCommand(FunGen1Ch, StatusGet); \
    // AddCommand(FunGen1Ch, PropsSet); \
    // AddCommand(FunGen1Ch, PropsGet); \
    // AddCommand(FunGen1Ch, IdleSet); \
    // AddCommand(FunGen1Ch, IdleGet); \
    // AddCommand(FunGen2Ch, Start); \
    // AddCommand(FunGen2Ch, Stop); \
    // AddCommand(FunGen2Ch, StatusGet); \
    // AddCommand(FunGen2Ch, IdleSet); \
    // AddCommand(FunGen2Ch, IdleGet); \
    // AddCommand(FunGen2Ch, OnOffSet); \
    // AddCommand(FunGen2Ch, OnOffGet); \
    // AddCommand(FunGen2Ch, SignalSet); \
    // AddCommand(FunGen2Ch, SignalGet); \
    // AddCommand(FunGen2Ch, PropsSet); \
    // AddCommand(FunGen2Ch, PropsGet); \
    // AddCommand(FunGen2Ch, WaveformSet); \
    // AddCommand(FunGen2Ch, WaveformGet); \
    // AddCommand(Util, SessionPathGet); \
    // AddCommand(Util, SettingsLoad); \
    // AddCommand(Util, SettingsSave); \
    // AddCommand(Util, LayoutLoad); \
    // AddCommand(Util, LayoutSave); \
    // AddCommand(Util, Lock); \
    // AddCommand(Util, UnLock); \
    // AddCommand(Util, RTFreqSet); \
    // AddCommand(Util, RTFreqGet); \
    // AddCommand(Util, AcqPeriodSet); \
    // AddCommand(Util, AcqPeriodGet); \
    // AddCommand(Util, RTOversamplSet); \
    // AddCommand(Util, RTOversamplGet); \
    // AddCommand(Util, Quit);    

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
    AddFunction(KelvinCtrl, GainGet); \
    AddFunction(KelvinCtrl, ModParamsSet); \
    AddFunction(KelvinCtrl, ModParamsGet); \
    AddFunction(KelvinCtrl, ModOnOffSet); \
    AddFunction(KelvinCtrl, ModOnOffGet); \
    AddFunction(KelvinCtrl, CtrlSignalSet); \
    AddFunction(KelvinCtrl, CtrlSignalGet); \
    AddFunction(KelvinCtrl, AmpGet); \
    AddFunction(KelvinCtrl, BiasLimitsSet); \
    AddFunction(KelvinCtrl, BiasLimitsGet);

#define AddPDCompFunctions \
    AddFunction(PDComp, Open); \
    AddFunction(PDComp, Close); \
    AddFunction(PDComp, ParamsSet); \
    AddFunction(PDComp, ParamsGet); \
    AddFunction(PDComp, DataGet);

#define AddCurrentFunctions \
    AddFunction(Current, Get); \
    AddFunction(Current, Get100); \
    AddFunction(Current, BEEMGet); \
    AddFunction(Current, GainSet); \
    AddFunction(Current, GainsGet); \
    AddFunction(Current, CalibrSet); \
    AddFunction(Current, CalibrGet);

#define AddZCtrlFunctions \
    AddFunction(ZCtrl, ZPosSet); \
    AddFunction(ZCtrl, ZPosGet); \
    AddFunction(ZCtrl, OnOffSet); \
    AddFunction(ZCtrl, OnOffGet); \
    AddFunction(ZCtrl, SetpntSet); \
    AddFunction(ZCtrl, SetpntGet); \
    AddFunction(ZCtrl, GainSet); \
    AddFunction(ZCtrl, GainGet); \
    AddFunction(ZCtrl, SwitchOffDelaySet); \
    AddFunction(ZCtrl, SwitchOffDelayGet); \
    AddFunction(ZCtrl, TipLiftSet); \
    AddFunction(ZCtrl, TipLiftGet); \
    AddFunction(ZCtrl, Home); \
    AddFunction(ZCtrl, HomePropsSet); \
    AddFunction(ZCtrl, HomePropsGet); \
    AddFunction(ZCtrl, ActiveCtrlSet); \
    AddFunction(ZCtrl, CtrlListGet); \
    AddFunction(ZCtrl, Withdraw); \
    AddFunction(ZCtrl, WithdrawRateSet); \
    AddFunction(ZCtrl, WithdrawRateGet); \
    AddFunction(ZCtrl, LimitsEnabledSet); \
    AddFunction(ZCtrl, LimitsEnabledGet); \
    AddFunction(ZCtrl, LimitsSet); \
    AddFunction(ZCtrl, LimitsGet); \
    AddFunction(ZCtrl, StatusGet);

#define AddSafeTipFunctions \
    AddFunction(SafeTip, OnOffSet); \
    AddFunction(SafeTip, OnOffGet); \
    AddFunction(SafeTip, SignalGet); \
    AddFunction(SafeTip, PropsSet); \
    AddFunction(SafeTip, PropsGet);

#define AddAutoApproachFunctions \
    AddFunction(AutoApproach, Open); \
    AddFunction(AutoApproach, OnOffSet); \
    AddFunction(AutoApproach, OnOffGet);

#define AddZSpectrFunctions \
    AddFunction(ZSpectr, Open); \
    AddFunction(ZSpectr, Start); \
    AddFunction(ZSpectr, Stop); \
    AddFunction(ZSpectr, StatusGet); \
    AddFunction(ZSpectr, ChsSet); \
    AddFunction(ZSpectr, ChsGet); \
    AddFunction(ZSpectr, PropsSet); \
    AddFunction(ZSpectr, PropsGet); \
    AddFunction(ZSpectr, AdvPropsSet); \
    AddFunction(ZSpectr, AdvPropsGet); \
    AddFunction(ZSpectr, RangeSet); \
    AddFunction(ZSpectr, RangeGet); \
    AddFunction(ZSpectr, TimingSet); \
    AddFunction(ZSpectr, TimingGet); \
    AddFunction(ZSpectr, RetractDelaySet); \
    AddFunction(ZSpectr, RetractDelayGet); \
    AddFunction(ZSpectr, RetractSet); \
    AddFunction(ZSpectr, RetractGet); \
    AddFunction(ZSpectr, Retract2ndSet); \
    AddFunction(ZSpectr, Retract2ndGet);

#define AddPiezoFunctions \
    AddFunction(Piezo, TiltSet); \
    AddFunction(Piezo, TiltGet); \
    AddFunction(Piezo, RangeSet); \
    AddFunction(Piezo, RangeGet); \
    AddFunction(Piezo, SensSet); \
    AddFunction(Piezo, SensGet); \
    AddFunction(Piezo, DriftCompSet); \
    AddFunction(Piezo, DriftCompGet); \
    AddFunction(Piezo, CalibrGet); \
    AddFunction(Piezo, HVAInfoGet); \
    AddFunction(Piezo, HVAStatusLEDGet);

#define AddScanFunctions \
    AddFunction(Scan, Action); \
    AddFunction(Scan, StatusGet); \
    AddFunction(Scan, WaitEndOfScan); \
    AddFunction(Scan, FrameSet); \
    AddFunction(Scan, FrameGet); \
    AddFunction(Scan, BufferSet); \
    AddFunction(Scan, BufferGet); \
    AddFunction(Scan, PropsSet); \
    AddFunction(Scan, PropsGet); \
    AddFunction(Scan, SpeedSet); \
    AddFunction(Scan, SpeedGet); \
    AddFunction(Scan, FrameDataGrab);

#define AddFolMeFunctions \
    AddFunction(FolMe, XYPosSet); \
    AddFunction(FolMe, XYPosGet); \
    AddFunction(FolMe, SpeedSet); \
    AddFunction(FolMe, SpeedGet); \
    AddFunction(FolMe, OversamplSet); \
    AddFunction(FolMe, OversamplGet); \
    AddFunction(FolMe, Stop); \
    AddFunction(FolMe, PSOnOffGet); \
    AddFunction(FolMe, PSOnOffSet); \
    AddFunction(FolMe, PSExpGet); \
    AddFunction(FolMe, PSExpSet); \
    AddFunction(FolMe, PSPropsGet); \
    AddFunction(FolMe, PSPropsSet);

#define AddTipRecFunctions \
    AddFunction(TipRec, BufferSizeSet); \
    AddFunction(TipRec, BufferSizeGet); \
    AddFunction(TipRec, BufferClear); \
    AddFunction(TipRec, DataGet); \
    AddFunction(TipRec, DataSave);

#define AddPatternFunctions \
    AddFunction(Pattern, ExpOpen); \
    AddFunction(Pattern, ExpStart); \
    AddFunction(Pattern, ExpPause); \
    AddFunction(Pattern, ExpStop); \
    AddFunction(Pattern, ExpStatusGet); \
    AddFunction(Pattern, GridSet); \
    AddFunction(Pattern, GridGet); \
    AddFunction(Pattern, LineSet); \
    AddFunction(Pattern, LineGet); \
    AddFunction(Pattern, CloudSet); \
    AddFunction(Pattern, CloudGet); \
    AddFunction(Pattern, PropsSet); \
    AddFunction(Pattern, PropsGet);

#define AddMarksFunctions \
    AddFunction(Marks, PointDraw); \
    AddFunction(Marks, PointsDraw); \
    AddFunction(Marks, LineDraw); \
    AddFunction(Marks, LinesDraw); \
    AddFunction(Marks, PointsErase); \
    AddFunction(Marks, LinesErase); \
    AddFunction(Marks, PointsVisibleSet); \
    AddFunction(Marks, LinesVisibleSet); \
    AddFunction(Marks, PointsGet); \
    AddFunction(Marks, LinesGet);

#define AddTipShaperFunctions \
    AddFunction(TipShaper, Start); \
    AddFunction(TipShaper, PropsSet); \
    AddFunction(TipShaper, PropsGet);

#define AddMotorFunctions \
    AddFunction(Motor, StartMove); \
    AddFunction(Motor, StartClosedLoop); \
    AddFunction(Motor, StopMove); \
    AddFunction(Motor, PosGet); \
    AddFunction(Motor, StepCounterGet); \
    AddFunction(Motor, FreqAmpGet); \
    AddFunction(Motor, FreqAmpSet);

#define AddGenSwpFunctions \
    AddFunction(GenSwp, AcqChsSet); \
    AddFunction(GenSwp, AcqChsGet); \
    AddFunction(GenSwp, SwpSignalSet); \
    AddFunction(GenSwp, SwpSignalGet); \
    AddFunction(GenSwp, LimitsSet); \
    AddFunction(GenSwp, LimitsGet); \
    AddFunction(GenSwp, PropsSet); \
    AddFunction(GenSwp, PropsGet); \
    AddFunction(GenSwp, Start); \
    AddFunction(GenSwp, Stop); \
    AddFunction(GenSwp, Open);

#define AddGenPICtrlFunctions \
    AddFunction(GenPICtrl, OnOffSet); \
    AddFunction(GenPICtrl, OnOffGet); \
    AddFunction(GenPICtrl, AOValSet); \
    AddFunction(GenPICtrl, AOValGet); \
    AddFunction(GenPICtrl, AOPropsSet); \
    AddFunction(GenPICtrl, AOPropsGet); \
    AddFunction(GenPICtrl, ModChSet); \
    AddFunction(GenPICtrl, ModChGet); \
    AddFunction(GenPICtrl, DemodChSet); \
    AddFunction(GenPICtrl, DemodChGet); \
    AddFunction(GenPICtrl, PropsSet); \
    AddFunction(GenPICtrl, PropsGet);

#define AddAtomTrackFunctions \
    AddFunction(AtomTrack, CtrlSet); \
    AddFunction(AtomTrack, StatusGet); \
    AddFunction(AtomTrack, PropsSet); \
    AddFunction(AtomTrack, PropsGet); \
    AddFunction(AtomTrack, QuickCompStart); \
    AddFunction(AtomTrack, DriftComp);

#define AddLockInFunctions \
    AddFunction(LockIn, ModOnOffSet); \
    AddFunction(LockIn, ModOnOffGet); \
    AddFunction(LockIn, ModSignalSet); \
    AddFunction(LockIn, ModSignalGet); \
    AddFunction(LockIn, ModPhasRegSet); \
    AddFunction(LockIn, ModPhasRegGet); \
    AddFunction(LockIn, ModHarmonicSet); \
    AddFunction(LockIn, ModHarmonicGet); \
    AddFunction(LockIn, ModPhasSet); \
    AddFunction(LockIn, ModPhasGet); \
    AddFunction(LockIn, ModAmpSet); \
    AddFunction(LockIn, ModAmpGet); \
    AddFunction(LockIn, ModPhasFreqSet); \
    AddFunction(LockIn, ModPhasFreqGet); \
    AddFunction(LockIn, DemodSignalSet); \
    AddFunction(LockIn, DemodSignalGet); \
    AddFunction(LockIn, DemodHarmonicSet); \
    AddFunction(LockIn, DemodHarmonicGet); \
    AddFunction(LockIn, DemodHPFilterSet); \
    AddFunction(LockIn, DemodHPFilterGet); \
    AddFunction(LockIn, DemodLPFilterSet); \
    AddFunction(LockIn, DemodLPFilterGet); \
    AddFunction(LockIn, DemodPhasRegSet); \
    AddFunction(LockIn, DemodPhasRegGet); \
    AddFunction(LockIn, DemodPhasSet); \
    AddFunction(LockIn, DemodPhasGet); \
    AddFunction(LockIn, DemodSyncFilterSet); \
    AddFunction(LockIn, DemodSyncFilterGet); \
    AddFunction(LockIn, DemodRTSignalsSet); \
    AddFunction(LockIn, DemodRTSignalsGet);

#define AddLockInFreqSwpFunctions \
    AddFunction(LockInFreqSwp, Open); \
    AddFunction(LockInFreqSwp, Start); \
    AddFunction(LockInFreqSwp, SignalSet); \
    AddFunction(LockInFreqSwp, SignalGet); \
    AddFunction(LockInFreqSwp, LimitsSet); \
    AddFunction(LockInFreqSwp, LimitsGet); \
    AddFunction(LockInFreqSwp, PropsSet); \
    AddFunction(LockInFreqSwp, PropsGet);

#define AddPLLFunctions \
    AddFunction(PLL, InpCalibrSet); \
    AddFunction(PLL, InpCalibrGet); \
    AddFunction(PLL, InpRangeSet); \
    AddFunction(PLL, InpRangeGet); \
    AddFunction(PLL, InpPropsSet); \
    AddFunction(PLL, InpPropsGet); \
    AddFunction(PLL, AddOnOffSet); \
    AddFunction(PLL, AddOnOffGet); \
    AddFunction(PLL, OutOnOffSet); \
    AddFunction(PLL, OutOnOffGet); \
    AddFunction(PLL, ExcRangeSet); \
    AddFunction(PLL, ExcRangeGet); \
    AddFunction(PLL, ExcitationSet); \
    AddFunction(PLL, ExcitationGet); \
    AddFunction(PLL, AmpCtrlSetpntSet); \
    AddFunction(PLL, AmpCtrlSetpntGet); \
    AddFunction(PLL, AmpCtrlOnOffSet); \
    AddFunction(PLL, AmpCtrlOnOffGet); \
    AddFunction(PLL, AmpCtrlGainSet); \
    AddFunction(PLL, AmpCtrlGainGet); \
    AddFunction(PLL, AmpCtrlBandwidthSet); \
    AddFunction(PLL, AmpCtrlBandwidthGet); \
    AddFunction(PLL, PhasCtrlOnOffSet); \
    AddFunction(PLL, PhasCtrlOnOffGet); \
    AddFunction(PLL, PhasCtrlGainSet); \
    AddFunction(PLL, PhasCtrlGainGet); \
    AddFunction(PLL, PhasCtrlBandwidthSet); \
    AddFunction(PLL, PhasCtrlBandwidthGet); \
    AddFunction(PLL, FreqRangeSet); \
    AddFunction(PLL, FreqRangeGet); \
    AddFunction(PLL, CenterFreqSet); \
    AddFunction(PLL, CenterFreqGet); \
    AddFunction(PLL, FreqShiftSet); \
    AddFunction(PLL, FreqShiftGet); \
    AddFunction(PLL, FreqShiftAutoCenter); \
    AddFunction(PLL, FreqExcOverwriteSet); \
    AddFunction(PLL, FreqExcOverwriteGet); \
    AddFunction(PLL, DemodInputSet); \
    AddFunction(PLL, DemodInputGet); \
    AddFunction(PLL, DemodHarmonicSet); \
    AddFunction(PLL, DemodHarmonicGet); \
    AddFunction(PLL, DemodPhasRefSet); \
    AddFunction(PLL, DemodPhasRefGet); \
    AddFunction(PLL, DemodFilterSet); \
    AddFunction(PLL, DemodFilterGet);

#define AddPLLQCtrlFunctions \
    AddFunction(PLLQCtrl, AccessRequest); \
    AddFunction(PLLQCtrl, AccessGet); \
    AddFunction(PLLQCtrl, OnOffSet); \
    AddFunction(PLLQCtrl, OnOffGet); \
    AddFunction(PLLQCtrl, QGainSet); \
    AddFunction(PLLQCtrl, QGainGet); \
    AddFunction(PLLQCtrl, PhaseSet); \
    AddFunction(PLLQCtrl, PhaseGet);

#define AddPLLFreqSwpFunctions \
    AddFunction(PLLFreqSwp, Open); \
    AddFunction(PLLFreqSwp, ParamsSet); \
    AddFunction(PLLFreqSwp, ParamsGet); \
    AddFunction(PLLFreqSwp, Start); \
    AddFunction(PLLFreqSwp, Stop);

#define AddPLLPhasSwpFunctions \
    AddFunction(PLLPhasSwp, Start); \
    AddFunction(PLLPhasSwp, Stop);

#define AddPLLSignalAnlzrFunctions \
    AddFunction(PLLSignalAnlzr, Open); \
    AddFunction(PLLSignalAnlzr, ChSet); \
    AddFunction(PLLSignalAnlzr, ChGet); \
    AddFunction(PLLSignalAnlzr, TimebaseSet); \
    AddFunction(PLLSignalAnlzr, TimebaseGet); \
    AddFunction(PLLSignalAnlzr, TrigAuto); \
    AddFunction(PLLSignalAnlzr, TrigRearm); \
    AddFunction(PLLSignalAnlzr, TrigSet); \
    AddFunction(PLLSignalAnlzr, TrigGet); \
    AddFunction(PLLSignalAnlzr, OsciDataGet); \
    AddFunction(PLLSignalAnlzr, FFTPropsSet); \
    AddFunction(PLLSignalAnlzr, FFTPropsGet); \
    AddFunction(PLLSignalAnlzr, FFTAvgRestart); \
    AddFunction(PLLSignalAnlzr, FFTDataGet);

#define AddPLLZoomFFTFunctions \
    AddFunction(PLLZoomFFT, Open); \
    AddFunction(PLLZoomFFT, ChSet); \
    AddFunction(PLLZoomFFT, ChGet); \
    AddFunction(PLLZoomFFT, AvgRestart); \
    AddFunction(PLLZoomFFT, PropsSet); \
    AddFunction(PLLZoomFFT, PropsGet); \
    AddFunction(PLLZoomFFT, DataGet);

#define AddOCSyncFunctions \
    AddFunction(OCSync, AnglesSet); \
    AddFunction(OCSync, AnglesGet); \
    AddFunction(OCSync, LinkAnglesSet); \
    AddFunction(OCSync, LinkAnglesGet);

#define AddScriptFunctions \
    AddFunction(Script, Load); \
    AddFunction(Script, Save); \
    AddFunction(Script, Deploy); \
    AddFunction(Script, Undeploy); \
    AddFunction(Script, Run); \
    AddFunction(Script, Stop); \
    AddFunction(Script, ChsGet); \
    AddFunction(Script, ChsSet); \
    AddFunction(Script, DataGet); \
    AddFunction(Script, Autosave);

#define AddInterfFunctions \
    AddFunction(Interf, CtrlOnOffSet); \
    AddFunction(Interf, CtrlOnOffGet); \
    AddFunction(Interf, CtrlPropsSet); \
    AddFunction(Interf, CtrlPropsGet); \
    AddFunction(Interf, WPiezoSet); \
    AddFunction(Interf, WPiezoGet); \
    AddFunction(Interf, ValGet); \
    AddFunction(Interf, CtrlCalibrOpen); \
    AddFunction(Interf, CtrlReset); \
    AddFunction(Interf, CtrlNullDefl);

#define AddLaserFunctions \
    AddFunction(Laser, OnOffSet); \
    AddFunction(Laser, OnOffGet); \
    AddFunction(Laser, PropsSet); \
    AddFunction(Laser, PropsGet); \
    AddFunction(Laser, PowerGet);

#define AddBeamDeflFunctions \
    AddFunction(BeamDefl, HorConfigSet); \
    AddFunction(BeamDefl, HorConfigGet); \
    AddFunction(BeamDefl, VerConfigSet); \
    AddFunction(BeamDefl, VerConfigGet); \
    AddFunction(BeamDefl, IntConfigSet); \
    AddFunction(BeamDefl, IntConfigGet); \
    AddFunction(BeamDefl, AutoOffset);

#define AddSignalsFunctions \
    AddFunction(Signals, NamesGet); \
    AddFunction(Signals, InSlotSet); \
    AddFunction(Signals, InSlotsGet); \
    AddFunction(Signals, CalibrGet); \
    AddFunction(Signals, RangeGet); \
    AddFunction(Signals, ValGet); \
    AddFunction(Signals, ValsGet); \
    AddFunction(Signals, MeasNamesGet); \
    AddFunction(Signals, AddRTGet); \
    AddFunction(Signals, AddRTSet);

#define AddUserInFunctions \
    AddFunction(UserIn, CalibrSet);

#define AddUserOutFunctions \
    AddFunction(UserOut, ModeSet); \
    AddFunction(UserOut, ModeGet); \
    AddFunction(UserOut, MonitorChSet); \
    AddFunction(UserOut, MonitorChGet); \
    AddFunction(UserOut, ValSet); \
    AddFunction(UserOut, CalibrSet); \
    AddFunction(UserOut, CalcSignalNameSet); \
    AddFunction(UserOut, CalcSignalNameGet); \
    AddFunction(UserOut, CalcSignalConfigSet); \
    AddFunction(UserOut, CalcSignalConfigGet); \
    AddFunction(UserOut, LimitsSet); \
    AddFunction(UserOut, LimitsGet);

#define AddDigLinesFunctions \
    AddFunction(DigLines, PropsSet); \
    AddFunction(DigLines, OutStatusSet); \
    AddFunction(DigLines, TTLValGet); \
    AddFunction(DigLines, Pulse);

#define AddDataLogFunctions \
    AddFunction(DataLog, Open); \
    AddFunction(DataLog, Start); \
    AddFunction(DataLog, Stop); \
    AddFunction(DataLog, StatusGet); \
    AddFunction(DataLog, ChsSet); \
    AddFunction(DataLog, ChsGet); \
    AddFunction(DataLog, PropsSet); \
    AddFunction(DataLog, PropsGet);

#define AddTCPLogFunctions \
    AddFunction(TCPLog, Start); \
    AddFunction(TCPLog, Stop); \
    AddFunction(TCPLog, ChsSet); \
    AddFunction(TCPLog, OversamplSet); \
    AddFunction(TCPLog, StatusGet);

#define AddOsciHRFunctions \
    AddFunction(OsciHR, ChSet); \
    AddFunction(OsciHR, ChGet); \
    AddFunction(OsciHR, OversamplSet); \
    AddFunction(OsciHR, OversamplGet); \
    AddFunction(OsciHR, CalibrModeSet); \
    AddFunction(OsciHR, CalibrModeGet); \
    AddFunction(OsciHR, SamplesSet); \
    AddFunction(OsciHR, SamplesGet); \
    AddFunction(OsciHR, PreTrigSet); \
    AddFunction(OsciHR, PreTrigGet); \
    AddFunction(OsciHR, Run); \
    AddFunction(OsciHR, OsciDataGet); \
    AddFunction(OsciHR, TrigModeSet); \
    AddFunction(OsciHR, TrigModeGet); \
    AddFunction(OsciHR, TrigLevChSet); \
    AddFunction(OsciHR, TrigLevChGet); \
    AddFunction(OsciHR, TrigLevValSet); \
    AddFunction(OsciHR, TrigLevValGet); \
    AddFunction(OsciHR, TrigLevHystSet); \
    AddFunction(OsciHR, TrigLevHystGet); \
    AddFunction(OsciHR, TrigLevSlopeSet); \
    AddFunction(OsciHR, TrigLevSlopeGet); \
    AddFunction(OsciHR, TrigDigChSet); \
    AddFunction(OsciHR, TrigDigChGet); \
    AddFunction(OsciHR, TrigArmModeSet); \
    AddFunction(OsciHR, TrigArmModeGet); \
    AddFunction(OsciHR, TrigDigSlopeSet); \
    AddFunction(OsciHR, TrigDigSlopeGet); \
    AddFunction(OsciHR, TrigRearm); \
    AddFunction(OsciHR, PSDShow); \
    AddFunction(OsciHR, PSDWeightSet); \
    AddFunction(OsciHR, PSDWeightGet); \
    AddFunction(OsciHR, PSDWindowSet); \
    AddFunction(OsciHR, PSDWindowGet); \
    AddFunction(OsciHR, PSDAvrgTypeSet); \
    AddFunction(OsciHR, PSDAvrgTypeGet); \
    AddFunction(OsciHR, PSDAvrgCountSet); \
    AddFunction(OsciHR, PSDAvrgCountGet); \
    AddFunction(OsciHR, PSDAvrgRestart); \
    AddFunction(OsciHR, PSDDataGet);

#define AddOsci1TFunctions \
    AddFunction(Osci1T, ChSet); \
    AddFunction(Osci1T, ChGet); \
    AddFunction(Osci1T, TimebaseSet); \
    AddFunction(Osci1T, TimebaseGet); \
    AddFunction(Osci1T, TrigSet); \
    AddFunction(Osci1T, TrigGet); \
    AddFunction(Osci1T, Run); \
    AddFunction(Osci1T, DataGet);

#define AddOsci2TFunctions \
    AddFunction(Osci2T, ChsSet); \
    AddFunction(Osci2T, ChsGet); \
    AddFunction(Osci2T, TimebaseSet); \
    AddFunction(Osci2T, TimebaseGet); \
    AddFunction(Osci2T, OversamplSet); \
    AddFunction(Osci2T, OversamplGet); \
    AddFunction(Osci2T, TrigSet); \
    AddFunction(Osci2T, TrigGet); \
    AddFunction(Osci2T, Run); \
    AddFunction(Osci2T, DataGet);

#define AddSignalChartFunctions \
    AddFunction(SignalChart, Open); \
    AddFunction(SignalChart, ChsSet); \
    AddFunction(SignalChart, ChsGet);

#define AddSpectrumAnlzrFunctions \
    AddFunction(SpectrumAnlzr, ChSet); \
    AddFunction(SpectrumAnlzr, ChGet); \
    AddFunction(SpectrumAnlzr, FreqRangeSet); \
    AddFunction(SpectrumAnlzr, FreqRangeGet); \
    AddFunction(SpectrumAnlzr, FreqResSet); \
    AddFunction(SpectrumAnlzr, FreqResGet); \
    AddFunction(SpectrumAnlzr, FFTWindowSet); \
    AddFunction(SpectrumAnlzr, FFTWindowGet); \
    AddFunction(SpectrumAnlzr, AveragSet); \
    AddFunction(SpectrumAnlzr, AveragGet); \
    AddFunction(SpectrumAnlzr, ACCouplingSet); \
    AddFunction(SpectrumAnlzr, ACCouplingGet); \
    AddFunction(SpectrumAnlzr, CursorPosSet); \
    AddFunction(SpectrumAnlzr, CursorPosGet); \
    AddFunction(SpectrumAnlzr, BandRMSGet); \
    AddFunction(SpectrumAnlzr, DCGet); \
    AddFunction(SpectrumAnlzr, Run); \
    AddFunction(SpectrumAnlzr, DataGet);

#define AddFunGen1ChFunctions \
    AddFunction(FunGen1Ch, Start); \
    AddFunction(FunGen1Ch, Stop); \
    AddFunction(FunGen1Ch, StatusGet); \
    AddFunction(FunGen1Ch, PropsSet); \
    AddFunction(FunGen1Ch, PropsGet); \
    AddFunction(FunGen1Ch, IdleSet); \
    AddFunction(FunGen1Ch, IdleGet);

#define AddFunGen2ChFunctions \
    AddFunction(FunGen2Ch, Start); \
    AddFunction(FunGen2Ch, Stop); \
    AddFunction(FunGen2Ch, StatusGet); \
    AddFunction(FunGen2Ch, IdleSet); \
    AddFunction(FunGen2Ch, IdleGet); \
    AddFunction(FunGen2Ch, OnOffSet); \
    AddFunction(FunGen2Ch, OnOffGet); \
    AddFunction(FunGen2Ch, SignalSet); \
    AddFunction(FunGen2Ch, SignalGet); \
    AddFunction(FunGen2Ch, PropsSet); \
    AddFunction(FunGen2Ch, PropsGet); \
    AddFunction(FunGen2Ch, WaveformSet); \
    AddFunction(FunGen2Ch, WaveformGet);

#define AddUtilFunctions \
    AddFunction(Util, SessionPathGet); \
    AddFunction(Util, SettingsLoad); \
    AddFunction(Util, SettingsSave); \
    AddFunction(Util, LayoutLoad); \
    AddFunction(Util, LayoutSave); \
    AddFunction(Util, Lock); \
    AddFunction(Util, UnLock); \
    AddFunction(Util, RTFreqSet); \
    AddFunction(Util, RTFreqGet); \
    AddFunction(Util, AcqPeriodSet); \
    AddFunction(Util, AcqPeriodGet); \
    AddFunction(Util, RTOversamplSet); \
    AddFunction(Util, RTOversamplGet); \
    AddFunction(Util, Quit);

#endif // MACRO_H
