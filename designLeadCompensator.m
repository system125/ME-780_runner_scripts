function leadCompensator = designLeadCompensator(w_c,phi,mag_G_jwc)
    %-- Adds max phase of Phi in degrees at w_c
    %-- LeadCompensator = struct{Ta,Td,Kp}
    phi_rad = deg2rad(phi);

    alpha = (1-sin(phi_rad))/(1 + sin(phi_rad));
    
    %-- Calculate the parameters
    Td = 1/(sqrt(alpha)*w_c); Ta = sqrt(alpha)/w_c;
    j = sqrt(-1);
    Kp = abs(j*w_c*Ta + 1)/( abs(j*w_c*Td + 1) * mag_G_jwc);


    % -- Output for function
    leadCompensator = struct();

    leadCompensator.Td = Td; leadCompensator.Ta = Ta;
    leadCompensator.Kp = Kp;
end