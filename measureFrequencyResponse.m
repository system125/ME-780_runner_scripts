load("pd_parameters.mat")
model = "bodeTestRunner";
load("system_parameters.mat")

enableSimModelFriction = true;
t_sim_start = 0;
t_dwell = 5;
Ts = 0.001;

%-- Controller Parameters
ad = exp(-T_sample*pd_param.a);
Kp = pd_param.Kp;
Kd = pd_param.Kd;
Ki = pd_param.Ki;

%-- frequency to test
%ws = logspace(-1,3,100);
ws = [5]

fs = ws/(2*pi);
N = 20;
t_sim_end = 5;

U_in =.1;

U_data = zeros(length(ws),3);
%%

for i = 1:length(ws)
    w_i = ws(i);
    disp("Running simulation for frequency:")
    


    ts = (t_sim_start:Ts:t_sim_end)';
    xd = U_in*sin(w_i*ts);
    xd = timeseries(xd,ts);

    set_param(model,"StartTime",string(t_sim_start));
    set_param(model,"StopTime",string(t_sim_end));
    set_param(model,"SimulationCommand","start");
    pause(t_sim_end+t_dwell);
    
    sineData = interpolateSineData(x_res.time,x_res.signals.values,fs(i));

    U_data(i,1) = ws(i); U_data(i,2) = 20*log10(sineData.U/U_in); U_data(i,3) = sineData.Phi;
end
%%

figure(1);
hold on;
xlabel("frequency [rad/s]->");
ylabel("Sine ->");
plot(x_sim_in.time,x_sim_in.signals.values);
plot(x_res.time,x_res.signals.values);
hold off;

save("bodeResponse.mat","sineData");