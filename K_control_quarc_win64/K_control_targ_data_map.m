    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (K_control_P)
        ;%
            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% K_control_P.Kd
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% K_control_P.Kp
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% K_control_P.k_acc
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% K_control_P.k_vel
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% K_control_P.DiscreteDerivative_ICPrevScaled
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% K_control_P.DiscreteDerivative_ICPrevScal_g
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% K_control_P.DiscreteDerivative1_ICPrevScale
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% K_control_P.HILReadEncoder1_channels
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% K_control_P.HILReadEncoder2_channels
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 1;

                    ;% K_control_P.HILWriteAnalog_channels
                    section.data(3).logicalSrcIdx = 9;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 35;
            section.data(35)  = dumData; %prealloc

                    ;% K_control_P.HILInitialize_OOTerminate
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% K_control_P.HILInitialize_OOExit
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 1;

                    ;% K_control_P.HILInitialize_OOStart
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 2;

                    ;% K_control_P.HILInitialize_OOEnter
                    section.data(4).logicalSrcIdx = 13;
                    section.data(4).dtTransOffset = 3;

                    ;% K_control_P.HILInitialize_AOFinal
                    section.data(5).logicalSrcIdx = 14;
                    section.data(5).dtTransOffset = 4;

                    ;% K_control_P.HILInitialize_POFinal
                    section.data(6).logicalSrcIdx = 15;
                    section.data(6).dtTransOffset = 5;

                    ;% K_control_P.HILInitialize_AIHigh
                    section.data(7).logicalSrcIdx = 16;
                    section.data(7).dtTransOffset = 6;

                    ;% K_control_P.HILInitialize_AILow
                    section.data(8).logicalSrcIdx = 17;
                    section.data(8).dtTransOffset = 7;

                    ;% K_control_P.HILInitialize_AOHigh
                    section.data(9).logicalSrcIdx = 18;
                    section.data(9).dtTransOffset = 8;

                    ;% K_control_P.HILInitialize_AOLow
                    section.data(10).logicalSrcIdx = 19;
                    section.data(10).dtTransOffset = 9;

                    ;% K_control_P.HILInitialize_AOInitial
                    section.data(11).logicalSrcIdx = 20;
                    section.data(11).dtTransOffset = 10;

                    ;% K_control_P.HILInitialize_AOWatchdog
                    section.data(12).logicalSrcIdx = 21;
                    section.data(12).dtTransOffset = 11;

                    ;% K_control_P.HILInitialize_POFrequency
                    section.data(13).logicalSrcIdx = 22;
                    section.data(13).dtTransOffset = 12;

                    ;% K_control_P.HILInitialize_POInitial
                    section.data(14).logicalSrcIdx = 23;
                    section.data(14).dtTransOffset = 13;

                    ;% K_control_P.HILInitialize_POWatchdog
                    section.data(15).logicalSrcIdx = 24;
                    section.data(15).dtTransOffset = 14;

                    ;% K_control_P.mmcn_Gain
                    section.data(16).logicalSrcIdx = 25;
                    section.data(16).dtTransOffset = 15;

                    ;% K_control_P.InverseModulus_Modulus
                    section.data(17).logicalSrcIdx = 26;
                    section.data(17).dtTransOffset = 16;

                    ;% K_control_P.mmcn2_Gain
                    section.data(18).logicalSrcIdx = 27;
                    section.data(18).dtTransOffset = 17;

                    ;% K_control_P.InverseModulus1_Modulus
                    section.data(19).logicalSrcIdx = 28;
                    section.data(19).dtTransOffset = 18;

                    ;% K_control_P.SineWave_Amp
                    section.data(20).logicalSrcIdx = 29;
                    section.data(20).dtTransOffset = 19;

                    ;% K_control_P.SineWave_Bias
                    section.data(21).logicalSrcIdx = 30;
                    section.data(21).dtTransOffset = 20;

                    ;% K_control_P.SineWave_Freq
                    section.data(22).logicalSrcIdx = 31;
                    section.data(22).dtTransOffset = 21;

                    ;% K_control_P.SineWave_Phase
                    section.data(23).logicalSrcIdx = 32;
                    section.data(23).dtTransOffset = 22;

                    ;% K_control_P.DiscreteTimeIntegrator_gainval
                    section.data(24).logicalSrcIdx = 33;
                    section.data(24).dtTransOffset = 23;

                    ;% K_control_P.DiscreteTimeIntegrator_IC
                    section.data(25).logicalSrcIdx = 34;
                    section.data(25).dtTransOffset = 24;

                    ;% K_control_P.TSamp_WtEt
                    section.data(26).logicalSrcIdx = 35;
                    section.data(26).dtTransOffset = 25;

                    ;% K_control_P.DiscreteTransferFcn_NumCoef
                    section.data(27).logicalSrcIdx = 36;
                    section.data(27).dtTransOffset = 26;

                    ;% K_control_P.DiscreteTransferFcn_DenCoef
                    section.data(28).logicalSrcIdx = 37;
                    section.data(28).dtTransOffset = 28;

                    ;% K_control_P.DiscreteTransferFcn_InitialStat
                    section.data(29).logicalSrcIdx = 38;
                    section.data(29).dtTransOffset = 30;

                    ;% K_control_P.Saturation_UpperSat
                    section.data(30).logicalSrcIdx = 39;
                    section.data(30).dtTransOffset = 31;

                    ;% K_control_P.Saturation_LowerSat
                    section.data(31).logicalSrcIdx = 40;
                    section.data(31).dtTransOffset = 32;

                    ;% K_control_P.CableGain_Gain
                    section.data(32).logicalSrcIdx = 41;
                    section.data(32).dtTransOffset = 33;

                    ;% K_control_P.TSamp_WtEt_i
                    section.data(33).logicalSrcIdx = 42;
                    section.data(33).dtTransOffset = 34;

                    ;% K_control_P.TSamp_WtEt_o
                    section.data(34).logicalSrcIdx = 43;
                    section.data(34).dtTransOffset = 35;

                    ;% K_control_P.Gain1_Gain
                    section.data(35).logicalSrcIdx = 44;
                    section.data(35).dtTransOffset = 36;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% K_control_P.HILInitialize_CKChannels
                    section.data(1).logicalSrcIdx = 45;
                    section.data(1).dtTransOffset = 0;

                    ;% K_control_P.HILInitialize_DOWatchdog
                    section.data(2).logicalSrcIdx = 46;
                    section.data(2).dtTransOffset = 1;

                    ;% K_control_P.HILInitialize_EIInitial
                    section.data(3).logicalSrcIdx = 47;
                    section.data(3).dtTransOffset = 2;

                    ;% K_control_P.HILInitialize_POModes
                    section.data(4).logicalSrcIdx = 48;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% K_control_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 49;
                    section.data(1).dtTransOffset = 0;

                    ;% K_control_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 50;
                    section.data(2).dtTransOffset = 2;

                    ;% K_control_P.HILInitialize_EIChannels
                    section.data(3).logicalSrcIdx = 51;
                    section.data(3).dtTransOffset = 4;

                    ;% K_control_P.HILInitialize_EIQuadrature
                    section.data(4).logicalSrcIdx = 52;
                    section.data(4).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 38;
            section.data(38)  = dumData; %prealloc

                    ;% K_control_P.HILInitialize_Active
                    section.data(1).logicalSrcIdx = 53;
                    section.data(1).dtTransOffset = 0;

                    ;% K_control_P.HILInitialize_AOTerminate
                    section.data(2).logicalSrcIdx = 54;
                    section.data(2).dtTransOffset = 1;

                    ;% K_control_P.HILInitialize_AOExit
                    section.data(3).logicalSrcIdx = 55;
                    section.data(3).dtTransOffset = 2;

                    ;% K_control_P.HILInitialize_DOTerminate
                    section.data(4).logicalSrcIdx = 56;
                    section.data(4).dtTransOffset = 3;

                    ;% K_control_P.HILInitialize_DOExit
                    section.data(5).logicalSrcIdx = 57;
                    section.data(5).dtTransOffset = 4;

                    ;% K_control_P.HILInitialize_POTerminate
                    section.data(6).logicalSrcIdx = 58;
                    section.data(6).dtTransOffset = 5;

                    ;% K_control_P.HILInitialize_POExit
                    section.data(7).logicalSrcIdx = 59;
                    section.data(7).dtTransOffset = 6;

                    ;% K_control_P.HILInitialize_CKPStart
                    section.data(8).logicalSrcIdx = 60;
                    section.data(8).dtTransOffset = 7;

                    ;% K_control_P.HILInitialize_CKPEnter
                    section.data(9).logicalSrcIdx = 61;
                    section.data(9).dtTransOffset = 8;

                    ;% K_control_P.HILInitialize_CKStart
                    section.data(10).logicalSrcIdx = 62;
                    section.data(10).dtTransOffset = 9;

                    ;% K_control_P.HILInitialize_CKEnter
                    section.data(11).logicalSrcIdx = 63;
                    section.data(11).dtTransOffset = 10;

                    ;% K_control_P.HILInitialize_AIPStart
                    section.data(12).logicalSrcIdx = 64;
                    section.data(12).dtTransOffset = 11;

                    ;% K_control_P.HILInitialize_AIPEnter
                    section.data(13).logicalSrcIdx = 65;
                    section.data(13).dtTransOffset = 12;

                    ;% K_control_P.HILInitialize_AOPStart
                    section.data(14).logicalSrcIdx = 66;
                    section.data(14).dtTransOffset = 13;

                    ;% K_control_P.HILInitialize_AOPEnter
                    section.data(15).logicalSrcIdx = 67;
                    section.data(15).dtTransOffset = 14;

                    ;% K_control_P.HILInitialize_AOStart
                    section.data(16).logicalSrcIdx = 68;
                    section.data(16).dtTransOffset = 15;

                    ;% K_control_P.HILInitialize_AOEnter
                    section.data(17).logicalSrcIdx = 69;
                    section.data(17).dtTransOffset = 16;

                    ;% K_control_P.HILInitialize_AOReset
                    section.data(18).logicalSrcIdx = 70;
                    section.data(18).dtTransOffset = 17;

                    ;% K_control_P.HILInitialize_DOPStart
                    section.data(19).logicalSrcIdx = 71;
                    section.data(19).dtTransOffset = 18;

                    ;% K_control_P.HILInitialize_DOPEnter
                    section.data(20).logicalSrcIdx = 72;
                    section.data(20).dtTransOffset = 19;

                    ;% K_control_P.HILInitialize_DOStart
                    section.data(21).logicalSrcIdx = 73;
                    section.data(21).dtTransOffset = 20;

                    ;% K_control_P.HILInitialize_DOEnter
                    section.data(22).logicalSrcIdx = 74;
                    section.data(22).dtTransOffset = 21;

                    ;% K_control_P.HILInitialize_DOReset
                    section.data(23).logicalSrcIdx = 75;
                    section.data(23).dtTransOffset = 22;

                    ;% K_control_P.HILInitialize_EIPStart
                    section.data(24).logicalSrcIdx = 76;
                    section.data(24).dtTransOffset = 23;

                    ;% K_control_P.HILInitialize_EIPEnter
                    section.data(25).logicalSrcIdx = 77;
                    section.data(25).dtTransOffset = 24;

                    ;% K_control_P.HILInitialize_EIStart
                    section.data(26).logicalSrcIdx = 78;
                    section.data(26).dtTransOffset = 25;

                    ;% K_control_P.HILInitialize_EIEnter
                    section.data(27).logicalSrcIdx = 79;
                    section.data(27).dtTransOffset = 26;

                    ;% K_control_P.HILInitialize_POPStart
                    section.data(28).logicalSrcIdx = 80;
                    section.data(28).dtTransOffset = 27;

                    ;% K_control_P.HILInitialize_POPEnter
                    section.data(29).logicalSrcIdx = 81;
                    section.data(29).dtTransOffset = 28;

                    ;% K_control_P.HILInitialize_POStart
                    section.data(30).logicalSrcIdx = 82;
                    section.data(30).dtTransOffset = 29;

                    ;% K_control_P.HILInitialize_POEnter
                    section.data(31).logicalSrcIdx = 83;
                    section.data(31).dtTransOffset = 30;

                    ;% K_control_P.HILInitialize_POReset
                    section.data(32).logicalSrcIdx = 84;
                    section.data(32).dtTransOffset = 31;

                    ;% K_control_P.HILInitialize_OOReset
                    section.data(33).logicalSrcIdx = 85;
                    section.data(33).dtTransOffset = 32;

                    ;% K_control_P.HILInitialize_DOFinal
                    section.data(34).logicalSrcIdx = 86;
                    section.data(34).dtTransOffset = 33;

                    ;% K_control_P.HILInitialize_DOInitial
                    section.data(35).logicalSrcIdx = 87;
                    section.data(35).dtTransOffset = 34;

                    ;% K_control_P.HILReadEncoder1_Active
                    section.data(36).logicalSrcIdx = 88;
                    section.data(36).dtTransOffset = 35;

                    ;% K_control_P.HILReadEncoder2_Active
                    section.data(37).logicalSrcIdx = 89;
                    section.data(37).dtTransOffset = 36;

                    ;% K_control_P.HILWriteAnalog_Active
                    section.data(38).logicalSrcIdx = 90;
                    section.data(38).dtTransOffset = 37;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (K_control_B)
        ;%
            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% K_control_B.mmcn
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% K_control_B.InverseModulus
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% K_control_B.mmcn2
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% K_control_B.SineWave
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% K_control_B.DiscreteTimeIntegrator
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% K_control_B.Gain2
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% K_control_B.TSamp
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% K_control_B.DiscreteTransferFcn
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 7;

                    ;% K_control_B.Sum1
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 8;

                    ;% K_control_B.Sum3
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 9;

                    ;% K_control_B.Saturation
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 10;

                    ;% K_control_B.TSamp_i
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 11;

                    ;% K_control_B.TSamp_g
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 12;

                    ;% K_control_B.Sum2
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 13;

                    ;% K_control_B.Gain1
                    section.data(15).logicalSrcIdx = 15;
                    section.data(15).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (K_control_DW)
        ;%
            section.nData     = 16;
            section.data(16)  = dumData; %prealloc

                    ;% K_control_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% K_control_DW.UD_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% K_control_DW.DiscreteTransferFcn_states
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% K_control_DW.UD_DSTATE_c
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% K_control_DW.UD_DSTATE_i
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% K_control_DW.HILInitialize_AIMinimums
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% K_control_DW.HILInitialize_AIMaximums
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 7;

                    ;% K_control_DW.HILInitialize_AOMinimums
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 9;

                    ;% K_control_DW.HILInitialize_AOMaximums
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 11;

                    ;% K_control_DW.HILInitialize_AOVoltages
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 13;

                    ;% K_control_DW.HILInitialize_FilterFrequency
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 15;

                    ;% K_control_DW.InverseModulus_PreviousInput
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 17;

                    ;% K_control_DW.InverseModulus_Revolutions
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 18;

                    ;% K_control_DW.InverseModulus1_PreviousInput
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 19;

                    ;% K_control_DW.InverseModulus1_Revolutions
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 20;

                    ;% K_control_DW.DiscreteTransferFcn_tmp
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 21;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% K_control_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% K_control_DW.HILReadEncoder1_PWORK
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% K_control_DW.HILReadEncoder2_PWORK
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% K_control_DW.FromWorkspace_PWORK.TimePtr
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 2;

                    ;% K_control_DW.HILWriteAnalog_PWORK
                    section.data(4).logicalSrcIdx = 20;
                    section.data(4).dtTransOffset = 3;

                    ;% K_control_DW.Scope_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 21;
                    section.data(5).dtTransOffset = 4;

                    ;% K_control_DW.ToWorkspace_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 22;
                    section.data(6).dtTransOffset = 6;

                    ;% K_control_DW.ToWorkspace1_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 23;
                    section.data(7).dtTransOffset = 7;

                    ;% K_control_DW.ToWorkspace2_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 24;
                    section.data(8).dtTransOffset = 8;

                    ;% K_control_DW.ToWorkspace3_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 25;
                    section.data(9).dtTransOffset = 9;

                    ;% K_control_DW.ToWorkspace4_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 26;
                    section.data(10).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% K_control_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% K_control_DW.HILInitialize_QuadratureModes
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 1;

                    ;% K_control_DW.HILInitialize_InitialEICounts
                    section.data(3).logicalSrcIdx = 29;
                    section.data(3).dtTransOffset = 3;

                    ;% K_control_DW.HILReadEncoder1_Buffer
                    section.data(4).logicalSrcIdx = 30;
                    section.data(4).dtTransOffset = 5;

                    ;% K_control_DW.HILReadEncoder2_Buffer
                    section.data(5).logicalSrcIdx = 31;
                    section.data(5).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% K_control_DW.FromWorkspace_IWORK.PrevIndex
                    section.data(1).logicalSrcIdx = 32;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% K_control_DW.InverseModulus_FirstSample
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

                    ;% K_control_DW.InverseModulus1_FirstSample
                    section.data(2).logicalSrcIdx = 34;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1134674048;
    targMap.checksum1 = 566475829;
    targMap.checksum2 = 1410947570;
    targMap.checksum3 = 1358366083;

