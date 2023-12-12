disp("####################")
disp("Q1. prelim")

m = 6.8930e-04;
b = 0.010585;
delta_x = 4.63e-04;
% dc_plus = 0.3201;
% dc_minus = -0.3201;

dc_plus = 0.34;
dc_minus = -0.3201;
Ts = 0.001;

phase_margin = 35;

wc = 50;
j = sqrt(-1);
G_jw = @(w) 1/(j*w*(m*j*w+b));

save("system_parameters.mat","m","b","delta_x","dc_plus","dc_minus","Ts")
%% -- Design lead compensator PD

ang_G_jw = -90 - rad2deg(atan2(m*wc,b));
ang_L_jw = -180+phase_margin;
phi = ang_L_jw - ang_G_jw;

lc_param = designLeadCompensator(wc,phi,abs(G_jw(wc)));

save("lead_compensator_param.mat","lc_param")

s =tf("s");
Kc = lc_param.Kp*(lc_param.Td*s+1)/(lc_param.Ta*s+1);
Gc = 1/(m*s^2+b*s);
Lc = Gc*Kc;


pd_param = designPD_lead_compensator(lc_param);
save("pd_parameters.mat","pd_param")

%% Design PID lead compensator

wc = 44;
load("system_parameters.mat")
j = sqrt(-1);
%G_jw = @(w) 1/(j*w*(m*j*w+b));


phi_I = -15;
phaseMargin = 35;
pid_param = designPID_lead_compensator(phaseMargin,wc,phi_I,G_jw);
pid_param
save("pid_parameters.mat","pid_param");

figure();
bode(Lc);
grid on;
