function pd_param = designPD_lead_compensator(lc_param)
    %-- Takes in lead compensator parameters and calculates parameters
    %-- for PD compensator
    %-- lc_params = struct{Ta,Td,Kp}
    Td = lc_param.Td; Ta = lc_param.Ta; Kp = lc_param.Kp;

    %-- [PD parameters]
    Kd = Kp*(Td-Ta);
    a = 1/Ta;

    %-- [lead compensator]

    pd_param = struct();

    pd_param.Kp = Kp; pd_param.Kd = Kd; pd_param.Ki = 0;
    pd_param.a = a;
end