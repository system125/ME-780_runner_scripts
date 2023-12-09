function out = interpolateSineData(t,v,f)
    %% -- Takes in sine response and calculates the magnitude gain and frequency phase shift
    % Here t -> time series value, v -> Measured output variable f->
    % Frequency of the signal
    % -> U gain of the signal and phi -> phase that matches the signal
    % Returns : sturct{U,Phi,M}
    omega = 2*pi*f;
    sin_wt = sin(omega*t);
    cos_wt = cos(omega*t);

    R = [sin_wt cos_wt ones(length(t),1)];

    % -- Inverting and interpolating data
   % R_inv = inv(R'*R)*R';
    data = R\v;

    U_cos_phi = data(1); U_sin_phi = data(2); % -- Sine values
 

    % -- Getting gain and phase values
    out = struct();

    out.U = sqrt(U_cos_phi^2 + U_sin_phi^2);
    out.Phi = atan2(U_sin_phi,U_cos_phi);
    out.M = data(3); %-- offset 
end