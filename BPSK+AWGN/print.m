function [ output_args ] = Untitled( input_args )
%UNTITLED 此处显示有关此函数的摘要
%   此处显示详细说明
A=load('Result.txt');%filename是你txt文档名称
[m n]=size(A);%m为A的行数，n为A的列数
for i=2:n
plot(A(:,1),A(:,i));
hold all
xlabel('Eb/N0');
ylabel('BER');
end

end