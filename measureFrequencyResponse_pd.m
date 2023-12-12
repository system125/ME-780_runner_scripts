clear all;
load("pd_parameters.mat")
model = "bodeTestRunner";
load("system_parameters.mat")

enableSimModelFriction = true;
t_sim_start = 0;
t_dwell = 5;
Ts = 0.001;

%-- Controller Parameters
ad = exp(-Ts*pd_param.a);
Kp = pd_param.Kp;
Kd = pd_param.Kd;
Ki = pd_param.Ki;
a = pd_param.a;

%-- frequency to test
ws = logspace(.7,2,20);


%ws = 2*pi*fs;
N = 20;
t_sim_end = 120;

T_sample = Ts;

U_data = zeros(length(ws),3);
%%
j = sqrt(-1);
% P_jw = @(w) Kp + Ki/(j*w)+ Kd*(pd_param.a*j*w)/(j*w+pd_param.a);

s = tf('s');
K_s = Kp + Kd*(pd_param.a*s)/(s + pd_param.a);

A0 = 1.5;
for i = 1:length(ws)
    w_i = ws(i);
    sprintf("Running simulation for frequency:%f",w_i)
    % -- First account for gain of controller 
    ts = (t_sim_start:Ts:t_sim_end)';
    x_p = sin(w_i*ts);
    ys = lsim(K_s,x_p,ts);
    t_mask = ts > 20;
    sinDta = interpolateSineData(ts(t_mask),ys(t_mask),w_i);

    U_in = A0/sinDta.U;

    xd = U_in*sin(w_i*ts);
    xd = timeseries(xd,ts);
    xd2 = 1.5*sin(w_i*ts);
    xd2 = timeseries(xd2,ts);

    set_param(model,"StartTime",string(t_sim_start));
    set_param(model,"StopTime",string(t_sim_end));
    set_param(model,"SimulationCommand","start");
    pause(t_sim_end+t_dwell);
    
    save(sprintf("./pd_freq_response/freq_response_%d.mat",i),"U_in","x_res","xd")
    t_mask = x_res.time > 20;
    sineData = interpolateSineData(x_res.time(t_mask),x_res.signals.values(t_mask),ws(i));

    U_data(i,1) = ws(i); U_data(i,2) = 20*log10(sineData.U/U_in); U_data(i,3) = sineData.Phi;
end
%%

figure();
hold on;


save("bodeResponse_pd.mat","sineData");