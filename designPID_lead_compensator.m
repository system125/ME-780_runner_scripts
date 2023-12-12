
function pid_param = designPID_lead_compensator(PM,wc,phi_PI,G_jw)
    %-- 
    % [Inputs] =
    %   wc -> Phase crossover frequency
    % PM -> Phase Margin
    %   phi_PI: phase for PI controller
    % -- Return Pid_param{Kp Ki Kd, a}
    
    % -- Calculating Ti
    Ti = 1/wc*tan(deg2rad(phi_PI + 90));

    % -- Calculating phase of lead compensation

    phi_Max = -180 + PM - rad2deg(angle(G_jw(wc))) - phi_PI;

    phi_Max_rad = deg2rad(phi_Max);
    s_phi_Max = sin(phi_Max_rad);
   
    % -- Computing parametrs for lead compensator
    alpha = (1 - s_phi_Max)/(1+s_phi_Max);

    Ta = sqrt(alpha)/wc;
    Td = 1/(sqrt(alpha)*wc);
    
    j = sqrt(-1);
    
    %-- now calculating K
    K = abs(j*wc)/abs(j*wc*Ti + 1) * abs(j*wc*Ta+1)/abs(j*wc*Td +1) * 1/(abs(G_jw(wc)));
    Ki = K;

    Kd = K*(Ti-Ta)*(Td-Ta);
    Kp = K*(Ti+Td-Ta);

    
    pid_param = struct();
    % -- PID param
    pid_param.Kp = Kp; pid_param.Ki = Ki;
    pid_param.Kd = Kd; pid_param.a = 1/Ta;
    %-- just for test
    pid_param.Ti = Ti; pid_param.K = K;
    pid_param.Ta = Ta; pid_param.Td = Td;

end