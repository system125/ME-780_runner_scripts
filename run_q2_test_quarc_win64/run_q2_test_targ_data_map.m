    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
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
        ;% Auto data (run_q2_test_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% run_q2_test_P.pid_param
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% run_q2_test_P.DiscreteDerivative_ICPrevScaled
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% run_q2_test_P.HILReadEncoder1_channels
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% run_q2_test_P.HILReadEncoder2_channels
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% run_q2_test_P.HILWriteAnalog_channels
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 28;
            section.data(28)  = dumData; %prealloc

                    ;% run_q2_test_P.HILInitialize_OOTerminate
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% run_q2_test_P.HILInitialize_OOExit
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

                    ;% run_q2_test_P.HILInitialize_OOStart
                    section.data(3).logicalSrcIdx = 7;
                    section.data(3).dtTransOffset = 2;

                    ;% run_q2_test_P.HILInitialize_OOEnter
                    section.data(4).logicalSrcIdx = 8;
                    section.data(4).dtTransOffset = 3;

                    ;% run_q2_test_P.HILInitialize_AOFinal
                    section.data(5).logicalSrcIdx = 9;
                    section.data(5).dtTransOffset = 4;

                    ;% run_q2_test_P.HILInitialize_POFinal
                    section.data(6).logicalSrcIdx = 10;
                    section.data(6).dtTransOffset = 5;

                    ;% run_q2_test_P.HILInitialize_AIHigh
                    section.data(7).logicalSrcIdx = 11;
                    section.data(7).dtTransOffset = 6;

                    ;% run_q2_test_P.HILInitialize_AILow
                    section.data(8).logicalSrcIdx = 12;
                    section.data(8).dtTransOffset = 7;

                    ;% run_q2_test_P.HILInitialize_AOHigh
                    section.data(9).logicalSrcIdx = 13;
                    section.data(9).dtTransOffset = 8;

                    ;% run_q2_test_P.HILInitialize_AOLow
                    section.data(10).logicalSrcIdx = 14;
                    section.data(10).dtTransOffset = 9;

                    ;% run_q2_test_P.HILInitialize_AOInitial
                    section.data(11).logicalSrcIdx = 15;
                    section.data(11).dtTransOffset = 10;

                    ;% run_q2_test_P.HILInitialize_AOWatchdog
                    section.data(12).logicalSrcIdx = 16;
                    section.data(12).dtTransOffset = 11;

                    ;% run_q2_test_P.HILInitialize_POFrequency
                    section.data(13).logicalSrcIdx = 17;
                    section.data(13).dtTransOffset = 12;

                    ;% run_q2_test_P.HILInitialize_POInitial
                    section.data(14).logicalSrcIdx = 18;
                    section.data(14).dtTransOffset = 13;

                    ;% run_q2_test_P.HILInitialize_POWatchdog
                    section.data(15).logicalSrcIdx = 19;
                    section.data(15).dtTransOffset = 14;

                    ;% run_q2_test_P.mmcn_Gain
                    section.data(16).logicalSrcIdx = 20;
                    section.data(16).dtTransOffset = 15;

                    ;% run_q2_test_P.InverseModulus_Modulus
                    section.data(17).logicalSrcIdx = 21;
                    section.data(17).dtTransOffset = 16;

                    ;% run_q2_test_P.mmcn2_Gain
                    section.data(18).logicalSrcIdx = 22;
                    section.data(18).dtTransOffset = 17;

                    ;% run_q2_test_P.InverseModulus1_Modulus
                    section.data(19).logicalSrcIdx = 23;
                    section.data(19).dtTransOffset = 18;

                    ;% run_q2_test_P.DiscreteTimeIntegrator_gainval
                    section.data(20).logicalSrcIdx = 24;
                    section.data(20).dtTransOffset = 19;

                    ;% run_q2_test_P.DiscreteTimeIntegrator_IC
                    section.data(21).logicalSrcIdx = 25;
                    section.data(21).dtTransOffset = 20;

                    ;% run_q2_test_P.TSamp_WtEt
                    section.data(22).logicalSrcIdx = 26;
                    section.data(22).dtTransOffset = 21;

                    ;% run_q2_test_P.DiscreteTransferFcn_NumCoef
                    section.data(23).logicalSrcIdx = 27;
                    section.data(23).dtTransOffset = 22;

                    ;% run_q2_test_P.DiscreteTransferFcn_DenCoef
                    section.data(24).logicalSrcIdx = 28;
                    section.data(24).dtTransOffset = 24;

                    ;% run_q2_test_P.DiscreteTransferFcn_InitialStat
                    section.data(25).logicalSrcIdx = 29;
                    section.data(25).dtTransOffset = 26;

                    ;% run_q2_test_P.Saturation_UpperSat
                    section.data(26).logicalSrcIdx = 30;
                    section.data(26).dtTransOffset = 27;

                    ;% run_q2_test_P.Saturation_LowerSat
                    section.data(27).logicalSrcIdx = 31;
                    section.data(27).dtTransOffset = 28;

                    ;% run_q2_test_P.CableGain_Gain
                    section.data(28).logicalSrcIdx = 32;
                    section.data(28).dtTransOffset = 29;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% run_q2_test_P.HILInitialize_CKChannels
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

                    ;% run_q2_test_P.HILInitialize_DOWatchdog
                    section.data(2).logicalSrcIdx = 34;
                    section.data(2).dtTransOffset = 1;

                    ;% run_q2_test_P.HILInitialize_EIInitial
                    section.data(3).logicalSrcIdx = 35;
                    section.data(3).dtTransOffset = 2;

                    ;% run_q2_test_P.HILInitialize_POModes
                    section.data(4).logicalSrcIdx = 36;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% run_q2_test_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 37;
                    section.data(1).dtTransOffset = 0;

                    ;% run_q2_test_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 38;
                    section.data(2).dtTransOffset = 2;

                    ;% run_q2_test_P.HILInitialize_EIChannels
                    section.data(3).logicalSrcIdx = 39;
                    section.data(3).dtTransOffset = 4;

                    ;% run_q2_test_P.HILInitialize_EIQuadrature
                    section.data(4).logicalSrcIdx = 40;
                    section.data(4).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 38;
            section.data(38)  = dumData; %prealloc

                    ;% run_q2_test_P.HILInitialize_Active
                    section.data(1).logicalSrcIdx = 41;
                    section.data(1).dtTransOffset = 0;

                    ;% run_q2_test_P.HILInitialize_AOTerminate
                    section.data(2).logicalSrcIdx = 42;
                    section.data(2).dtTransOffset = 1;

                    ;% run_q2_test_P.HILInitialize_AOExit
                    section.data(3).logicalSrcIdx = 43;
                    section.data(3).dtTransOffset = 2;

                    ;% run_q2_test_P.HILInitialize_DOTerminate
                    section.data(4).logicalSrcIdx = 44;
                    section.data(4).dtTransOffset = 3;

                    ;% run_q2_test_P.HILInitialize_DOExit
                    section.data(5).logicalSrcIdx = 45;
                    section.data(5).dtTransOffset = 4;

                    ;% run_q2_test_P.HILInitialize_POTerminate
                    section.data(6).logicalSrcIdx = 46;
                    section.data(6).dtTransOffset = 5;

                    ;% run_q2_test_P.HILInitialize_POExit
                    section.data(7).logicalSrcIdx = 47;
                    section.data(7).dtTransOffset = 6;

                    ;% run_q2_test_P.HILInitialize_CKPStart
                    section.data(8).logicalSrcIdx = 48;
                    section.data(8).dtTransOffset = 7;

                    ;% run_q2_test_P.HILInitialize_CKPEnter
                    section.data(9).logicalSrcIdx = 49;
                    section.data(9).dtTransOffset = 8;

                    ;% run_q2_test_P.HILInitialize_CKStart
                    section.data(10).logicalSrcIdx = 50;
                    section.data(10).dtTransOffset = 9;

                    ;% run_q2_test_P.HILInitialize_CKEnter
                    section.data(11).logicalSrcIdx = 51;
                    section.data(11).dtTransOffset = 10;

                    ;% run_q2_test_P.HILInitialize_AIPStart
                    section.data(12).logicalSrcIdx = 52;
                    section.data(12).dtTransOffset = 11;

                    ;% run_q2_test_P.HILInitialize_AIPEnter
                    section.data(13).logicalSrcIdx = 53;
                    section.data(13).dtTransOffset = 12;

                    ;% run_q2_test_P.HILInitialize_AOPStart
                    section.data(14).logicalSrcIdx = 54;
                    section.data(14).dtTransOffset = 13;

                    ;% run_q2_test_P.HILInitialize_AOPEnter
                    section.data(15).logicalSrcIdx = 55;
                    section.data(15).dtTransOffset = 14;

                    ;% run_q2_test_P.HILInitialize_AOStart
                    section.data(16).logicalSrcIdx = 56;
                    section.data(16).dtTransOffset = 15;

                    ;% run_q2_test_P.HILInitialize_AOEnter
                    section.data(17).logicalSrcIdx = 57;
                    section.data(17).dtTransOffset = 16;

                    ;% run_q2_test_P.HILInitialize_AOReset
                    section.data(18).logicalSrcIdx = 58;
                    section.data(18).dtTransOffset = 17;

                    ;% run_q2_test_P.HILInitialize_DOPStart
                    section.data(19).logicalSrcIdx = 59;
                    section.data(19).dtTransOffset = 18;

                    ;% run_q2_test_P.HILInitialize_DOPEnter
                    section.data(20).logicalSrcIdx = 60;
                    section.data(20).dtTransOffset = 19;

                    ;% run_q2_test_P.HILInitialize_DOStart
                    section.data(21).logicalSrcIdx = 61;
                    section.data(21).dtTransOffset = 20;

                    ;% run_q2_test_P.HILInitialize_DOEnter
                    section.data(22).logicalSrcIdx = 62;
                    section.data(22).dtTransOffset = 21;

                    ;% run_q2_test_P.HILInitialize_DOReset
                    section.data(23).logicalSrcIdx = 63;
                    section.data(23).dtTransOffset = 22;

                    ;% run_q2_test_P.HILInitialize_EIPStart
                    section.data(24).logicalSrcIdx = 64;
                    section.data(24).dtTransOffset = 23;

                    ;% run_q2_test_P.HILInitialize_EIPEnter
                    section.data(25).logicalSrcIdx = 65;
                    section.data(25).dtTransOffset = 24;

                    ;% run_q2_test_P.HILInitialize_EIStart
                    section.data(26).logicalSrcIdx = 66;
                    section.data(26).dtTransOffset = 25;

                    ;% run_q2_test_P.HILInitialize_EIEnter
                    section.data(27).logicalSrcIdx = 67;
                    section.data(27).dtTransOffset = 26;

                    ;% run_q2_test_P.HILInitialize_POPStart
                    section.data(28).logicalSrcIdx = 68;
                    section.data(28).dtTransOffset = 27;

                    ;% run_q2_test_P.HILInitialize_POPEnter
                    section.data(29).logicalSrcIdx = 69;
                    section.data(29).dtTransOffset = 28;

                    ;% run_q2_test_P.HILInitialize_POStart
                    section.data(30).logicalSrcIdx = 70;
                    section.data(30).dtTransOffset = 29;

                    ;% run_q2_test_P.HILInitialize_POEnter
                    section.data(31).logicalSrcIdx = 71;
                    section.data(31).dtTransOffset = 30;

                    ;% run_q2_test_P.HILInitialize_POReset
                    section.data(32).logicalSrcIdx = 72;
                    section.data(32).dtTransOffset = 31;

                    ;% run_q2_test_P.HILInitialize_OOReset
                    section.data(33).logicalSrcIdx = 73;
                    section.data(33).dtTransOffset = 32;

                    ;% run_q2_test_P.HILInitialize_DOFinal
                    section.data(34).logicalSrcIdx = 74;
                    section.data(34).dtTransOffset = 33;

                    ;% run_q2_test_P.HILInitialize_DOInitial
                    section.data(35).logicalSrcIdx = 75;
                    section.data(35).dtTransOffset = 34;

                    ;% run_q2_test_P.HILReadEncoder1_Active
                    section.data(36).logicalSrcIdx = 76;
                    section.data(36).dtTransOffset = 35;

                    ;% run_q2_test_P.HILReadEncoder2_Active
                    section.data(37).logicalSrcIdx = 77;
                    section.data(37).dtTransOffset = 36;

                    ;% run_q2_test_P.HILWriteAnalog_Active
                    section.data(38).logicalSrcIdx = 78;
                    section.data(38).dtTransOffset = 37;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
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
        ;% Auto data (run_q2_test_B)
        ;%
            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% run_q2_test_B.mmcn
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% run_q2_test_B.InverseModulus
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% run_q2_test_B.mmcn2
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% run_q2_test_B.FromWorkspace2
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% run_q2_test_B.DiscreteTimeIntegrator
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% run_q2_test_B.Kd
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% run_q2_test_B.TSamp
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% run_q2_test_B.DiscreteTransferFcn
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 7;

                    ;% run_q2_test_B.Sum1
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 8;

                    ;% run_q2_test_B.Saturation
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 9;

                    ;% run_q2_test_B.Ki
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 10;

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
        ;% Auto data (run_q2_test_DW)
        ;%
            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% run_q2_test_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% run_q2_test_DW.UD_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% run_q2_test_DW.DiscreteTransferFcn_states
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% run_q2_test_DW.HILInitialize_AIMinimums
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% run_q2_test_DW.HILInitialize_AIMaximums
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% run_q2_test_DW.HILInitialize_AOMinimums
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

                    ;% run_q2_test_DW.HILInitialize_AOMaximums
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 9;

                    ;% run_q2_test_DW.HILInitialize_AOVoltages
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 11;

                    ;% run_q2_test_DW.HILInitialize_FilterFrequency
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 13;

                    ;% run_q2_test_DW.InverseModulus_PreviousInput
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 15;

                    ;% run_q2_test_DW.InverseModulus_Revolutions
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 16;

                    ;% run_q2_test_DW.InverseModulus1_PreviousInput
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 17;

                    ;% run_q2_test_DW.InverseModulus1_Revolutions
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 18;

                    ;% run_q2_test_DW.DiscreteTransferFcn_tmp
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% run_q2_test_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% run_q2_test_DW.HILReadEncoder1_PWORK
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% run_q2_test_DW.HILReadEncoder2_PWORK
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% run_q2_test_DW.FromWorkspace2_PWORK.TimePtr
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 2;

                    ;% run_q2_test_DW.HILWriteAnalog_PWORK
                    section.data(4).logicalSrcIdx = 18;
                    section.data(4).dtTransOffset = 3;

                    ;% run_q2_test_DW.Scope_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 19;
                    section.data(5).dtTransOffset = 4;

                    ;% run_q2_test_DW.ToWorkspace_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 20;
                    section.data(6).dtTransOffset = 7;

                    ;% run_q2_test_DW.ToWorkspace1_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 21;
                    section.data(7).dtTransOffset = 8;

                    ;% run_q2_test_DW.ToWorkspace2_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 22;
                    section.data(8).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% run_q2_test_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% run_q2_test_DW.HILInitialize_QuadratureModes
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

                    ;% run_q2_test_DW.HILInitialize_InitialEICounts
                    section.data(3).logicalSrcIdx = 25;
                    section.data(3).dtTransOffset = 3;

                    ;% run_q2_test_DW.HILReadEncoder1_Buffer
                    section.data(4).logicalSrcIdx = 26;
                    section.data(4).dtTransOffset = 5;

                    ;% run_q2_test_DW.HILReadEncoder2_Buffer
                    section.data(5).logicalSrcIdx = 27;
                    section.data(5).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% run_q2_test_DW.FromWorkspace2_IWORK.PrevIndex
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% run_q2_test_DW.InverseModulus_FirstSample
                    section.data(1).logicalSrcIdx = 29;
                    section.data(1).dtTransOffset = 0;

                    ;% run_q2_test_DW.InverseModulus1_FirstSample
                    section.data(2).logicalSrcIdx = 30;
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


    targMap.checksum0 = 1057297960;
    targMap.checksum1 = 1440676637;
    targMap.checksum2 = 2236585629;
    targMap.checksum3 = 1381286502;

