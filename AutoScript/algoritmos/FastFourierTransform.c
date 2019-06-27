#include <stdio.h>
#include <math.h>
#include <complex.h>

#define TAM 2048

double PI;
typedef double complex cplx;
 
void _fft(cplx buf[], cplx out[], int n, int step)
{
	if (step < n) {
		_fft(out, buf, n, step * 2);
		_fft(out + step, buf + step, n, step * 2);
 
		for (int i = 0; i < n; i += 2 * step) {
			cplx t = cexp(-I * PI * i / n) * out[i + step];
			buf[i / 2]     = out[i] + t;
			buf[(i + n)/2] = out[i] - t;
		}
	}
}
 
void fft(cplx buf[], int n)
{
	cplx out[n];
	for (int i = 0; i < n; i++) out[i] = buf[i];
 
	_fft(buf, out, n, 1);
}
 
int main()
{
	PI = atan2(1, 1) * 4;
	cplx buf[TAM] = { 4064216.97, 441212.34, 3195267.01, 8859327.10, 448987.36, 5484194.86, 1032372.09, 662876.34, 7947125.92, 5809469.88, 8753280.96, 9732503.86, 7157862.40, 3525702.57, 5490783.82, 8013664.21, 3092013.31, 1055690.34, 3054738.11, 4694036.92, 3809003.69, 7539092.76, 9352189.61, 6249908.92, 6004391.87, 3996413.65, 8228618.50, 8119464.71, 2168397.30, 602245.68, 9025368.92, 7907888.28, 5217816.07, 1466119.72, 5338319.77, 1664156.57, 1559914.86, 5410969.75, 9268167.15, 4380970.85, 4563041.16, 8864856.67, 5133548.52, 6982687.85, 526749.95, 9964739.66, 8021890.27, 227341.07, 9115794.93, 6365937.88, 6679990.93, 7255581.44, 711164.19, 4422477.56, 1824767.66, 5972061.10, 6549558.91, 8888996.02, 2689543.98, 4814326.30, 9612702.12, 4371166.42, 1479734.74, 7543921.74, 5375251.23, 9257819.72, 4318823.59, 5319585.82, 8788354.88, 9734410.81, 1204756.66, 8666232.64, 2041140.05, 8699521.31, 8731760.04, 418743.41, 8961534.09, 2046022.32, 7873667.73, 6594543.55, 1328598.97, 3223941.42, 1358576.21, 6940591.74, 5110101.07, 4456978.05, 7505434.53, 8313443.27, 6574132.68, 339609.54, 3647869.08, 7054096.46, 3131445.39, 9684927.13, 5092935.28, 3980824.47, 7723264.02, 3531685.44, 8896578.14, 4674255.50, 7184692.25, 710220.61, 4473444.94, 8515933.41, 5889121.89, 8186789.50, 6145482.22, 4119125.94, 9431536.13, 921287.11, 4527013.56, 8055020.45, 923537.24, 4928964.53, 417685.35, 5175695.53, 1367945.00, 5590434.87, 9011266.91, 6752652.53, 8890249.90, 7383438.79, 1867378.74, 9930646.94, 3010232.19, 2242740.36, 3696017.20, 9207999.78, 9447334.54, 3114411.97, 3820379.30, 609144.67, 9821521.32, 3251737.94, 7228191.99, 6660998.55, 7103726.78, 4924203.61, 4807043.18, 4824369.25, 1977871.44, 7259765.99, 6626249.66, 3606920.70, 241089.33, 2920816.87, 9276989.16, 8813696.81, 6777206.86, 6391863.23, 7140344.13, 1066570.48, 3819887.73, 135914.26, 3250879.03, 3264064.71, 8371451.53, 3313246.18, 182339.74, 8020515.92, 6971121.32, 8006721.88, 9128965.82, 1052187.07, 3621629.60, 3497062.09, 1324984.31, 7227763.56, 6355437.92, 5531925.16, 535734.12, 3841519.03, 6484729.47, 321738.15, 3283816.72, 5891622.00, 7133716.55, 2318516.10, 6213277.25, 9550210.84, 8410104.92, 6915521.98, 509059.09, 3306246.19, 9988131.48, 8701906.89, 5942687.96, 5776906.13, 4999517.61, 4395170.90, 3280541.97, 4792022.06, 3578713.15, 1272636.83, 8584850.87, 1603654.95, 3156600.98, 6788743.42, 3384747.30, 2229431.72, 5636929.33, 5903807.12, 944817.88, 4077539.19, 9999949.73, 8217775.14, 343911.33, 5554843.84, 9337199.26, 5321756.25, 7709533.80, 4103843.50, 8100816.17, 465220.22, 2751996.06, 6689655.51, 5858277.89, 7086611.14, 6571761.49, 4752557.10, 3582159.07, 2569142.74, 9282347.20, 4316965.87, 6832834.95, 2127152.92, 9349395.42, 3641631.59, 297857.91, 4596170.00, 288801.13, 6407427.70, 6434362.00, 9640505.53, 9386603.97, 3288820.36, 5141278.04, 3368632.30, 8054099.69, 9429376.59, 4256265.05, 5823498.60, 6747856.34, 6258099.31, 9231834.79, 7253155.82, 3150409.11, 8496047.78, 627433.95, 1744985.74, 9579088.87, 4312428.44, 6491036.74, 1706288.18, 6863859.71, 1077539.25, 2400738.66, 6763971.86, 4177337.96, 895899.96, 5491787.26, 9978350.82, 5034803.47, 9128886.59, 3164326.09, 7204250.41, 6709918.93, 9982795.15, 662796.70, 3596820.07, 5143444.04, 5197254.28, 8217216.97, 2211474.51, 1060359.95, 6689457.78, 7458190.55, 1958548.06, 9071951.36, 746119.95, 4477110.49, 274411.58, 736356.71, 9001872.95, 4129295.81, 4509947.41, 2143683.75, 7944872.17, 5673887.27, 5346166.80, 9599187.20, 2943628.57, 4973681.52, 4501098.84, 30886.82, 2282100.59, 8647997.09, 5243338.46, 6832152.40, 499464.88, 8747721.04, 6428069.11, 79024.18, 7943999.65, 1867560.59, 4156739.20, 6239365.33, 3376445.00, 7026052.26, 9846361.59, 5078955.76, 5811311.10, 6148926.80, 2209886.38, 9393892.55, 3866642.07, 7757679.68, 2462801.77, 2401174.94, 6540350.63, 2025624.54, 6774195.55, 2479097.20, 8041022.06, 2118014.41, 7323587.94, 2032992.48, 279253.91, 8363511.67, 5349322.40, 4513568.83, 2624922.23, 9157762.90, 5745524.42, 5507109.73, 1843880.16, 5498486.43, 2779282.91, 1093454.66, 6951943.51, 9673401.37, 5430675.79, 1376610.37, 1903020.05, 1176548.14, 3260688.76, 4124641.64, 32246.06, 686527.94, 9260243.17, 274911.51, 7045525.82, 4017876.73, 3424725.34, 2501257.06, 8211382.40, 8192703.28, 4456623.15, 5518901.27, 1021464.10, 4222237.14, 3726962.87, 9600504.99, 2838624.71, 9148154.59, 4726863.28, 832384.10, 7240035.53, 9969640.14, 9921658.90, 130114.73, 541512.04, 1518089.38, 3836168.93, 1709462.68, 1874701.83, 825054.20, 8431321.08, 7553573.87, 7052648.53, 2802322.13, 5466722.42, 2653948.67, 4892556.93, 7629836.18, 1220338.26, 9499407.62, 9226152.04, 4927126.01, 7484573.86, 7793940.43, 7192365.96, 1445125.43, 4639813.01, 7693944.70, 334341.39, 290859.93, 8389387.69, 8735096.07, 9089631.19, 8305308.35, 6987478.95, 6336031.70, 4611347.17, 4568243.79, 1241781.48, 4097560.02, 4556768.05, 7971289.64, 801353.12, 7726706.17, 1107430.83, 4696465.59, 622484.28, 1794576.00, 5481332.96, 7137376.86, 2868892.97, 437469.50, 5674890.89, 9289710.15, 9978720.32, 9868422.49, 8281799.77, 3095085.09, 4631905.06, 9523903.31, 1802808.44, 6657234.95, 7128920.68, 9130550.68, 6453058.27, 1672845.32, 4613038.36, 2958370.40, 9442561.09, 1863709.77, 2308599.39, 9227158.55, 2582879.18, 3794292.32, 3897186.06, 5447881.62, 2420269.86, 8328968.89, 7911914.26, 3756115.87, 4742256.22, 4406988.44, 5150915.21, 2726665.98, 4744226.80, 7083464.06, 2102633.30, 1457580.39, 1873606.68, 3488395.61, 5134914.67, 5838752.12, 1015707.69, 6082567.82, 6691190.20, 7393983.67, 9931054.19, 8572385.32, 4716821.54, 8793984.63, 549505.45, 3687617.30, 1122347.09, 5221165.32, 830083.10, 9460821.65, 3433568.90, 5138879.84, 1919109.88, 461672.71, 9462959.61, 2950423.40, 2718247.04, 2644096.75, 2303916.55, 8015715.71, 4183593.72, 229291.78, 7822970.62, 3542228.88, 319424.69, 1011199.50, 9002656.86, 3255660.56, 20195.50, 6037398.21, 6791670.16, 9500616.84, 4659597.33, 4921481.72, 2254767.93, 7611543.73, 4816582.14, 6946740.79, 1423640.64, 605881.36, 8794730.26, 9729571.37, 7814450.83, 2670867.96, 765548.37, 1058168.38, 8089218.38, 3946595.59, 2814373.39, 2536152.62, 4794573.32, 5844392.35, 5094941.49, 130377.01, 9189843.56, 6109618.10, 3461589.95, 8261793.22, 8796106.83, 3857034.55, 742459.85, 204809.35, 1584657.15, 3426538.89, 7909930.96, 7422725.79, 5602426.19, 7932872.98, 2949158.40, 9222132.61, 2446677.77, 5563298.33, 1439376.45, 4798785.26, 1485793.86, 6342538.14, 6126180.73, 2868063.09, 6899817.59, 1058081.48, 3886895.72, 8331969.72, 5693794.77, 3362010.05, 7932365.76, 3298930.89, 3824115.17, 8943152.09, 9810793.45, 7944448.54, 3724571.91, 2395349.37, 4606890.46, 417711.42, 3459737.09, 3998982.82, 965592.11, 3019241.80, 1393253.87, 5369325.21, 7973642.11, 7246162.91, 4560270.59, 2868703.25, 8480115.50, 433220.55, 4455660.44, 6166789.34, 7563628.99, 8989683.79, 1349613.12, 366451.45, 582969.72, 6427924.35, 7299459.18, 5534569.33, 1255154.19, 1134398.56, 7476064.38, 6635378.01, 2866683.89, 7869134.55, 8639938.66, 8183763.86, 8473616.08, 3659750.94, 9344334.01, 2328249.36, 7215327.24, 4587634.50, 7898537.52, 4609705.11, 1088204.55, 8066372.84, 7134387.60, 1307235.39, 1977115.74, 5183575.36, 2235355.79, 4380871.31, 7496616.21, 5596764.88, 8960575.38, 8861343.71, 317175.77, 7814267.40, 2410100.32, 5759774.67, 2421011.59, 3624772.78, 6219971.75, 1765792.40, 2076667.29, 4956660.74, 9352972.14, 2548867.56, 1289454.56, 4802019.41, 450700.00, 1546723.54, 767201.96, 8218404.21, 2063459.50, 7395265.68, 9137493.48, 3690474.56, 3123622.91, 1192180.61, 2405506.52, 4171303.74, 6383331.41, 3246972.06, 1912126.17, 6568257.39, 3820909.69, 3468796.34, 3076409.10, 1461071.11, 7485125.32, 5227745.17, 7963684.49, 4545961.00, 685889.98, 2544057.50, 105804.85, 7438822.87, 6722309.03, 8931971.41, 7857982.94, 5855794.43, 4503913.58, 5053251.40, 2393725.21, 9516324.54, 6972485.52, 3826663.20, 5386436.01, 3121949.29, 1848846.03, 9980827.09, 8436250.63, 6684355.04, 2395114.89, 3057661.12, 7427763.05, 9992748.91, 65517.26, 7934051.76, 815335.26, 5183884.05, 8532569.29, 3040609.34, 1285130.71, 8776669.64, 9529364.70, 3643320.52, 9725082.15, 8227444.88, 5606288.18, 7862406.45, 1937389.90, 2129261.90, 612775.34, 3190627.33, 5117806.50, 189789.95, 9692269.31, 2329793.70, 5561397.93, 4572360.45, 4456004.27, 9034719.28, 4078102.69, 7904531.25, 2329708.65, 1130524.45, 4573424.82, 9802585.95, 9719412.40, 6922512.12, 9565216.24, 9931820.28, 5135959.86, 4334473.89, 4799472.17, 6034801.39, 8581101.13, 4606814.44, 4390240.66, 6085208.03, 5633753.73, 4032780.54, 7290081.70, 8907530.24, 6251805.54, 6760008.14, 5001086.68, 5646803.33, 7694838.82, 5938296.44, 4927964.65, 4348196.50, 1174938.43, 3547863.62, 4514900.07, 3719659.22, 1101842.37, 197378.26, 5137640.47, 7345430.90, 4932028.05, 7309636.91, 5279960.10, 6123682.53, 4923244.77, 4739587.18, 9392844.55, 4277196.19, 5991584.31, 7423484.93, 4905891.73, 6031117.53, 9630472.78, 6763956.24, 5328336.99, 5821523.11, 7010568.68, 9381836.54, 1070866.31, 9122573.82, 8684969.68, 7409956.83, 1128852.19, 211414.86, 2831484.40, 7502585.26, 1499689.25, 235047.80, 871345.48, 8413767.76, 1513939.96, 1042872.28, 8827688.60, 8409775.13, 3982072.22, 2715049.20, 3665414.39, 584482.62, 9243963.51, 9097811.92, 3080198.33, 2924141.26, 8467687.82, 7593431.97, 8744347.38, 285529.48, 9464654.50, 8258195.99, 1703329.59, 7937312.53, 8907947.79, 4900689.15, 6409936.56, 4740591.72, 9629874.78, 7326001.01, 8892169.75, 2642398.80, 328637.72, 3677.96, 3702644.42, 2974254.85, 3660324.60, 4607376.42, 6732592.93, 1291228.47, 1886110.51, 5691698.45, 7934196.19, 1508978.98, 1699867.02, 6050343.46, 7490627.60, 2584010.39, 9700178.13, 4560721.40, 5252668.37, 767608.85, 6507453.12, 2244564.17, 4781764.99, 3993596.79, 8625738.83, 3734832.52, 1441258.02, 1315194.15, 1205836.41, 2431136.30, 1592343.53, 2165869.60, 1833856.53, 4105328.58, 3471366.16, 955126.88, 6877964.98, 395531.59, 374272.72, 5754228.12, 702131.45, 7924871.02, 8540819.89, 9603916.17, 6096405.82, 6870657.55, 7555575.43, 4224681.02, 5495962.82, 1971415.76, 6502484.83, 6097476.43, 9990543.66, 4944381.08, 7760727.20, 952756.26, 1448946.93, 7376655.79, 5808797.39, 6450360.35, 3762462.94, 8268974.43, 9402273.47, 923499.37, 1409685.24, 9626412.98, 9599805.13, 7157819.47, 9169747.98, 2188604.05, 2385679.84, 3911268.34, 5831206.13, 9990596.33, 6662154.97, 2038761.69, 1973763.80, 8409118.53, 2701646.45, 6070241.41, 8687121.84, 7164778.40, 7946809.39, 7125325.69, 1247183.95, 2519016.69, 636617.42, 6082923.14, 6578273.72, 9315924.78, 4482365.43, 9349696.68, 6104773.28, 1968302.71, 6386979.82, 6706857.53, 5832352.80, 2853535.14, 1946703.94, 3392769.66, 8858084.52, 6720465.90, 9985696.99, 700824.98, 8221885.54, 8219150.17, 5106366.13, 9265058.37, 2624169.24, 7572773.75, 7509971.75, 4200773.61, 7851840.64, 4666652.25, 5263851.21, 6437729.48, 5020005.93, 7556063.20, 2690816.09, 2832934.36, 9122644.89, 8712247.86, 8611531.29, 5507971.87, 4360807.97, 3705600.85, 8395783.65, 1141162.01, 203251.12, 2305165.85, 6913200.38, 1039256.79, 2711156.59, 5830321.43, 40415.80, 5256403.46, 4733090.11, 2631061.00, 676909.99, 7001596.51, 6008927.15, 6215441.73, 5946334.09, 678787.73, 74768.77, 4652121.95, 5359101.78, 3293808.75, 8825494.22, 1333256.41, 7198856.72, 9742182.07, 8856260.00, 8349292.65, 5154230.58, 826348.48, 3805515.31, 736257.44, 8197398.13, 3980351.46, 658003.24, 7063129.01, 1664202.04, 2263557.22, 6853048.79, 6728183.48, 5874986.35, 5268707.30, 695202.18, 9686260.35, 198308.10, 1879187.22, 5509255.50, 3863009.74, 1896345.54, 3791599.81, 8813222.20, 2202049.61, 187425.63, 2926250.98, 4148825.60, 8889935.04, 7184689.60, 1692555.29, 351909.32, 2210565.70, 964167.01, 6626887.97, 1161394.27, 7033743.36, 875806.54, 6092380.98, 824990.62, 1403319.51, 3749795.80, 2660138.61, 1713429.52, 4716064.88, 7073147.39, 6031916.42, 1650395.51, 3133046.93, 5486696.29, 4267275.31, 9977156.93, 801113.05, 5305175.92, 5585160.94, 7143124.56, 3844813.74, 5059269.88, 2237305.10, 8994693.52, 3737656.74, 2597006.35, 7348265.63, 9906764.80, 997632.79, 6789086.84, 8280714.42, 3793541.09, 2603157.62, 3405746.88, 245396.06, 6094237.40, 7117288.67, 2074072.37, 3633778.01, 7414980.78, 623820.60, 5397924.74, 7632209.41, 672748.10, 3965195.33, 5842335.07, 2314774.94, 225055.33, 1466588.05, 7195434.70, 219625.24, 7508269.08, 7450881.85, 6346353.16, 304069.15, 2810868.68, 3823064.27, 9154903.86, 4496250.82, 1636061.40, 9689197.67, 718466.52, 9781320.18, 9025162.67, 7698258.75, 6609051.48, 2000372.56, 4238708.46, 2737963.22, 9764666.14, 3691279.40, 1042634.48, 7896925.14, 2955218.03, 4982686.35, 6950094.64, 1268118.03, 314959.71, 5211959.33, 491809.61, 5494881.11, 3926507.17, 7162939.96, 7249130.76, 3255677.41, 1951269.75, 2266084.30, 105527.12, 351360.70, 2118399.94, 1017460.56, 5598763.88, 4605805.63, 3642998.29, 4858158.32, 1623405.05, 8421427.37, 1421129.50, 5154830.33, 75777.13, 5510788.93, 2034624.02, 3850751.20, 1998245.45, 6304569.42, 3605616.96, 4321584.80, 3526536.12, 6839233.40, 8619505.45, 4423570.92, 6318799.37, 8620425.64, 7248869.40, 4820104.42, 3505610.65, 2552429.86, 3366457.25, 6532299.91, 664787.47, 6635957.07, 4208830.87, 366652.26, 9709648.71, 1270430.76, 611468.86, 8241063.88, 1403924.75, 5277816.52, 9237751.75, 7056847.35, 855558.91, 2522767.42, 5797862.89, 8296928.71, 6094823.46, 6655288.46, 5065931.59, 8830522.86, 6092571.86, 78797.25, 7279279.82, 3183660.91, 221114.15, 3683276.83, 362321.87, 4814539.07, 2727053.78, 206532.38, 9211925.36, 2780301.17, 6202462.35, 9884358.02, 6456727.97, 9196211.47, 5803832.97, 7391924.95, 1870357.77, 5063562.91, 2875601.59, 5464415.81, 6947063.69, 6256138.96, 6287859.57, 2667122.73, 5895046.12, 7081498.88, 5085849.01, 8191210.05, 3248971.78, 1517019.04, 8381476.41, 8265202.02, 8847667.21, 685379.32, 2342404.96, 3316702.07, 650959.33, 2685556.40, 2136241.09, 2487983.45, 111111.74, 89923.15, 1178650.82, 1464992.37, 6480891.67, 7103865.43, 9731935.14, 1715657.20, 2643137.87, 3704565.24, 6634764.62, 6926455.94, 3958442.13, 5709739.36, 8040570.29, 2501553.17, 4407569.13, 1842273.39, 8831561.81, 5371482.84, 3202120.70, 265085.48, 433799.73, 3588598.20, 1906109.52, 640272.95, 6395757.40, 1096761.30, 9357365.68, 4415207.86, 1241200.81, 6735062.44, 5465047.30, 3634621.70, 980445.55, 7432464.27, 3396283.98, 4974569.90, 6526054.23, 963634.90, 9439726.09, 2494754.95, 5732762.03, 9343711.50, 1788186.73, 4811962.02, 414805.45, 7246845.85, 2501918.84, 5608334.92, 3572468.59, 6290631.54, 6788726.57, 3770907.10, 1955347.76, 2290411.21, 6222325.51, 4473041.27, 5117444.96, 3653850.27, 9025154.91, 267040.20, 9488905.71, 2531859.59, 6006611.09, 4425514.02, 6279706.66, 7002834.82, 7201335.86, 613768.90, 6440273.56, 9598801.52, 7969471.92, 3093648.82, 5900609.33, 7365862.14, 8074878.31, 5274083.57, 9685079.10, 60743.86, 7672938.94, 1672151.76, 974352.72, 8992554.28, 8349725.54, 6739190.45, 3678149.46, 6085585.35, 1006098.49, 348759.16, 9132559.71, 6082241.21, 5515533.23, 2837822.74, 2189970.83, 3782134.55, 2521324.43, 1881617.83, 1330920.20, 9917738.11, 6581295.10, 8090978.34, 5773652.58, 9692549.48, 9509024.86, 1205210.97, 5829905.12, 7388775.33, 1810355.00, 2684898.06, 4699546.56, 3420269.05, 4007285.41, 9394374.32, 235067.33, 6572412.02, 4013741.58, 6096895.12, 8452418.31, 4370258.39, 6119949.33, 3663252.83, 8385122.61, 7762601.55, 7785851.71, 6461481.43, 3409622.36, 819272.38, 1671309.25, 9055880.89, 3780902.12, 9901247.69, 8750122.31, 7665006.27, 2542146.87, 6475832.73, 7453321.26, 8304192.16, 4340078.60, 836214.80, 9618871.69, 1696709.61, 7203322.99, 3396494.19, 9069100.08, 1858758.84, 8837688.36, 7777897.54, 8427365.01, 386191.08, 2713107.30, 2523512.57, 4121888.74, 2077706.54, 9957811.57, 1562979.08, 1626792.16, 3048124.00, 9423891.94, 4425273.04, 9249801.78, 5779539.52, 5684951.77, 1034248.13, 7464444.86, 6729342.24, 404325.74, 1645991.84, 5730497.88, 653556.23, 7963322.15, 5403315.99, 9556080.98, 4707896.94, 319210.61, 3156433.24, 2087592.47, 6147663.85, 474940.98, 5070149.03, 6528768.26, 8197865.00, 9908629.37, 6958989.41, 7469759.15, 6744308.12, 6658054.36, 1241220.11, 8624438.65, 6146661.94, 2563230.51, 8951850.40, 7279906.93, 8298360.96, 7065596.01, 2640420.58, 3537596.95, 5483766.21, 5327872.51, 1850268.19, 6542434.10, 6623975.59, 5308104.72, 9644103.97, 3522750.40, 1702675.88, 4802880.98, 3710774.64, 9431605.93, 2313212.35, 9164194.87, 6245524.72, 8808372.86, 9258152.85, 5831795.60, 7786917.08, 8235475.04, 8378578.63, 718997.76, 417786.12, 5207386.63, 3625196.49, 1894818.21, 8389263.61, 2079443.82, 7089397.31, 3519948.74, 3820231.62, 3226065.05, 1444226.01, 8605991.76, 1669833.05, 9418763.58, 9536671.54, 7537852.36, 5301800.27, 939052.56, 2366790.05, 3797253.40, 6404324.90, 5898162.15, 2455115.60, 994979.30, 8375377.49, 3607623.66, 8505509.79, 9472752.03, 1267418.39, 644563.02, 2846386.01, 3290920.08, 3438465.39, 7642268.10, 5681697.70, 3881440.85, 963178.10, 6666352.96, 5145710.83, 9075340.96, 1083948.42, 3986774.62, 224067.14, 936259.83, 8104276.52, 2427073.60, 260646.77, 8766901.43, 5945143.69, 2527448.87, 5421449.74, 3664395.92, 9354704.05, 1187470.28, 7270880.81, 1906844.99, 3632589.01, 8390283.05, 8566424.93, 6040692.17, 6398963.88, 8850301.18, 9269756.79, 1498450.92, 4498216.57, 4341701.53, 4524419.43, 8995969.59, 721236.19, 6455249.16, 4989310.43, 5037927.61, 2161574.71, 8454694.73, 7395684.89, 6556846.78, 7351470.17, 9681704.92, 472276.14, 7710788.46, 6242174.71, 4519477.67, 5392880.07, 1152852.90, 6510446.31, 2832843.27, 3293422.00, 5914841.78, 4635369.69, 8008983.28, 6257002.63, 835193.92, 8400906.59, 2152926.51, 1225736.97, 3720250.21, 4639763.33, 3029664.25, 7391503.29, 6462480.14, 3165120.98, 3646663.22, 842036.80, 7815576.16, 3049530.27, 6414852.45, 6327242.87, 3947066.18, 3027765.04, 1823807.87, 709617.64, 2457294.41, 1011884.64, 8778657.78, 6556915.05, 586311.52, 6909777.68, 5731689.85, 1097754.27, 3290975.66, 491098.80, 9582215.74, 3705254.11, 3877521.05, 5690467.44, 5119853.59, 9301277.78, 5697522.63, 4246042.32, 2729860.76, 8615563.69, 2738557.47, 6449671.19, 9171234.95, 8568771.85, 7397549.44, 6824718.40, 9742372.65, 5090800.68, 7541143.80, 7644283.46, 9756787.77, 5417160.07, 7098916.52, 7608717.73, 131983.85, 3332141.16, 8198060.33, 5112203.06, 1932084.26, 8837260.78, 6469371.94, 7564622.37, 4881603.88, 3685329.20, 6091388.45, 1611419.72, 7486498.61, 7407706.31, 8250295.11, 1183924.83, 764883.72, 4689609.25, 8081149.59, 752247.36, 2983485.46, 1987655.38, 6741037.21, 5487249.77, 8724646.12, 474028.69, 2012449.69, 5039880.09, 6603344.40, 2848172.75, 8474788.50, 8035054.89, 3095527.71, 5532538.19, 5023711.67, 738628.72, 1458358.51, 6690827.01, 8406257.02, 2289193.67, 2622353.27, 9780567.70, 5686490.98, 2201889.98, 2864747.92, 7045552.00, 2793024.31, 2398331.48, 4565046.94, 7822981.67, 9595724.58, 1324196.75, 6944473.04, 7026035.68, 1148669.26, 8316181.23, 9130010.07, 3506388.01, 4024073.54, 5495592.84, 3879137.36, 9447410.92, 2060456.34, 5187332.80, 6077051.71, 9469010.91, 8456063.66, 9693045.81, 9368256.13, 7160277.83, 6089320.44, 7779574.85, 9535899.60, 7221993.86, 3085365.52, 1764778.09, 8889404.69, 4322592.52, 4676375.87, 1574050.86, 3045278.71, 1271683.07, 1784760.97, 7329294.20, 9358948.67, 2748828.01, 6926005.39, 5360729.47, 9452506.84, 8684569.55, 8824595.60, 3368965.07, 1019112.44, 1726828.07, 2866341.92, 2032328.81, 5097762.41, 1036031.50, 748426.16, 9570125.98, 6237951.79, 3420210.19, 3279746.30, 8688736.49, 3024830.46, 560537.71, 7549632.72, 9826945.25, 3412688.83, 417754.98, 9254117.91, 1196942.45, 4635510.30, 8838214.01, 6856208.08, 5628257.86, 9528527.10, 1057464.77, 9199879.18, 4219930.66, 8127699.13, 9372906.86, 3686290.99, 7643778.03, 337401.40, 8647280.01, 1794881.34, 4806323.52, 751812.09, 789218.45, 9225272.13, 1882915.15, 5612605.63, 6827138.12, 3813881.54, 4843552.93, 8435236.05, 3101725.82, 8073771.59, 4819403.83, 4848993.43, 9816959.52, 1803437.64, 6362799.06, 2289848.52, 8064461.57, 265213.86, 5080151.31, 1300280.05, 2263063.96, 3293765.73, 245463.35, 9950257.45, 4783621.82, 6874859.51, 3439556.92, 8445087.23, 4391972.49, 7873324.87, 2720462.47, 670001.47, 9140555.49, 845694.64, 1751079.01, 5101121.11, 1838322.02, 2128044.62, 3065503.91, 1365994.84, 7890546.32, 6470667.68, 6203184.95, 8023147.13, 5233724.08, 5033651.23, 828703.07, 1897422.56, 911556.67, 1734056.01, 639880.52, 5242749.39, 193984.28, 2564969.95, 6425557.93, 6308191.92, 8127076.32, 916573.55, 4343627.30, 4406668.69, 4471824.71, 971799.10, 9113603.40, 4120097.81, 8501894.55, 279574.83, 8662292.10, 9743428.48, 7471880.68, 6341936.96, 8666448.17, 9044167.54, 5212492.40, 2908430.82, 2966764.99, 5182550.85, 4170660.19, 6487971.12, 9639876.02, 3915174.28, 1334303.64, 2088010.42, 1936472.21, 1305662.19, 4383577.69, 8566995.99, 8318202.10, 9877742.71, 2265273.25, 8032076.38, 6358453.91, 2629629.05, 1788239.33, 5676108.31, 1313701.00, 9597275.57, 8369838.86, 4926779.15, 1946003.81, 7168972.42, 8835632.75, 1276588.75, 9449714.33, 9029142.81, 8449595.11, 6926234.77, 3315712.45, 8534631.86, 8800660.11, 6411244.42, 5903805.97, 4156308.04, 8530445.70, 8499266.05, 5750526.18, 4467067.58, 2231490.21, 7168313.26, 375229.02, 3461259.63, 7830914.20, 7377433.19, 7621911.13, 2289602.11, 8279216.53, 5096289.02, 8394257.47, 5795395.62, 5517060.97, 1648568.74, 7802307.83, 6110371.79, 3193239.00, 8981248.16, 1778980.38, 5413448.20, 4319457.40, 6486591.65, 8048564.68, 4130607.90, 3176421.22, 2947051.20, 988841.85, 4447541.97, 9002918.13, 5846517.13, 4893286.20, 7116305.96, 1583442.12, 6466529.96, 6171979.10, 7539684.68, 5954983.72, 7873985.90, 2887165.87, 4398154.09, 1710570.92, 8566760.65, 7032511.50, 6786944.85, 1664216.40, 4566800.22, 7596561.92, 9076088.91, 1446960.21, 2936232.45, 3853054.30, 9394648.45, 9190569.97, 793698.18, 3296851.23, 9840204.14, 5597274.49, 9937832.82, 5116622.56, 8557507.56, 7296404.11, 4265946.74, 7370703.23, 845961.19, 883805.25, 7811033.06, 8203521.50, 8736943.75, 2482111.98, 5890700.67, 4878516.99, 3742050.65, 6103482.59, 2425206.70, 7456126.83, 3876397.86, 3210259.20, 3214396.44, 1746394.28, 3797067.44, 6712456.81, 991180.75, 7548516.10, 3738011.12, 4576856.11, 1612861.77, 3422682.17, 928519.60, 5376295.78, 4677110.08, 1111428.84, 5233657.88, 9887170.71, 6774467.69, 5194704.37, 8734879.34, 2186461.30, 1952596.67, 7536435.15, 5199557.57, 3608083.26, 3872559.38, 3861971.95, 9227852.99, 4200676.23, 2584462.07, 2367002.72, 8064960.08, 534495.89, 8997324.95, 25490.60, 7065445.40, 36737.06, 6536743.70, 1395932.03, 4685344.41, 7595508.29, 6064102.19, 5407376.60, 5910121.38, 3428195.89, 9223325.55, 1037712.06, 5241342.01, 7335003.30, 8410838.71, 1002594.42, 3752659.07, 9246033.31, 6041066.90, 6663654.31, 9804062.39, 9945893.47, 6212876.78, 3691370.67, 6268882.26, 660951.90, 7857514.66, 3364757.13, 8031623.60, 7844032.52, 5256849.71, 5531959.27, 5925183.44, 6167471.68, 3979358.95, 447153.11, 3618871.66, 8417797.42, 9952039.62, 7316484.83, 1510726.69, 6292857.91, 4822687.18, 7969932.50, 5459792.09, 8950372.09, 2540104.59, 4181826.39, 440284.17, 7221404.41, 6877558.49, 6481470.60, 6045747.22, 4251155.20, 5990579.19, 848115.35, 7027231.49, 9458333.14, 2604472.87, 7401101.27, 8604764.58, 8954830.56, 5321799.26, 3721697.33, 1186272.50, 3005231.63, 7658654.11, 55564.71, 756438.83, 7976752.56, 6438202.85, 4653892.73, 4063150.79, 529701.70, 9662395.94, 2275116.26, 2286063.77, 7268955.98, 5136810.69, 2076766.07, 3931564.25, 1182306.45, 4154525.35, 7052072.61, 847720.24, 3195740.71, 4324962.69, 2846098.31, 690148.66, 9398748.51, 1578960.84, 4741084.66, 5459675.83, 6467571.62, 5750394.35, 7289381.88, 9474339.99, 1393331.62, 5588446.07, 3172354.73, 8006198.72, 7131825.74, 8627898.22, 5913588.37, 7849719.35, 6512179.84, 5418918.58, 2780372.89, 4056380.52, 9983580.15, 5123987.29, 8699382.02, 8465266.19, 4176256.46, 1377336.17, 1572288.78, 1113462.40, 1789401.95, 7241809.13, 471452.89, 107333.88, 6870536.99, 6954109.51, 7239016.20, 529763.75, 8197475.71, 2658444.63, 5607113.23, 7197554.02, 3086855.03, 6410338.61, 4359534.67, 9082445.72, 2311153.90, 6224066.66, 1789609.74, 1368703.74, 5913263.41, 2839508.49, 2547542.40, 1579051.84, 2276358.49, 4913425.13, 9610891.78, 6260169.55, 2067635.28, 8608572.72, 8135796.14, 1146405.63, 4291576.62, 6120713.51, 9254700.56, 4133958.53, 6570369.40, 3990105.51, 5860398.15, 832817.13, 9158830.88, 4595590.41, 5110346.28, 1763139.95, 9035691.46, 6404718.27, 1510692.86, 3318395.59, 2188813.15, 2542527.25 };
 
 	printf("Calculando FFT...\n");
	fft(buf, TAM);
	printf("Done :)\n");
 
	return 0;
}