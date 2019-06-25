/*! @file
 *
 *  @brief calculation of voltages and currents
 *
 *
 *  @author Lucien Tran
 *  @date 2019-04-16
 */


#include "calculation.h"
#include "OS.h"
#include "PIT.h"

// Hardcoded 2 dimensional array. first dimension refers to the IDMT characteristic (TCharacteristic). Second dimension is the goal to reach for the circuit to trip. The index corresponds to the current RMS in ms *100  to make it an int
static float TripTimes[3][1898] =
{
  {
    189397,142726,114721,96050,82712,72708,64926,58700,53604,49358,45764,42683,40012,37675,35612,33778,32137,30659,29322,28106,26995,25977,25040,24175,23373,22629,21936,21288,20683,20115,19581,19078,18604,18156,17733,17331,16950,16587,16243,15914,15601,15302,15016,14742,14480,14228,13987,13755,13533,13318,13112,12914,12722,12537,12359,12187,12020,11859,11703,11552,11406,11264,11127,10993,10864,10738,10616,10498,10382,10270,10161,10055,9951,9850,9752,9656,9563,9471,9382,9296,9211,9128,9047,8968,8891,8815,8741,8669,8598,8529,8461,8395,8330,8266,8203,8142,8082,8023,7966,7909,7853,7799,7745,7693,7641,7591,7541,7492,7444,7397,7350,7305,7260,7216,7172,7130,7088,7047,7006,6966,6927,6888,6850,6812,6775,6739,6703,6668,6633,6598,6565,6531,6498,6466,6434,6402,6371,6341,6311,6281,6251,6222,6194,6165,6137,6110,6083,6056,6029,6003,5977,5952,5926,5902,5877,5853,5829,5805,5781,5758,5735,5713,5690,5668,5646,5625,5603,5582,5561,5541,5520,5500,5480,5460,5441,5421,5402,5383,5364,5346,5327,5309,5291,5273,5256,5238,5221,5204,5187,5170,5153,5137,5121,5105,5089,5073,5057,5042,5026,5011,4996,4981,4966,4951,4937,4922,4908,4894,4880,4866,4852,4838,4825,4811,4798,4785,4772,4759,4746,4733,4720,4708,4695,4683,4671,4659,4647,4635,4623,4611,4599,4588,4576,4565,4554,4542,4531,4520,4509,4498,4488,4477,4466,4456,4445,4435,4425,4414,4404,4394,4384,4374,4364,4355,4345,4335,4326,4316,4307,4297,4288,4279,4269,4260,4251,4242,4233,4225,4216,4207,4198,4190,4181,4173,4164,4156,4147,4139,4131,4123,4114,4106,4098,4090,4082,4075,4067,4059,4051,4044,4036,4028,4021,4013,4006,3998,3991,3984,3977,3969,3962,3955,3948,3941,3934,3927,3920,3913,3906,3899,3893,3886,3879,3873,3866,3859,3853,3846,3840,3834,3827,3821,3815,3808,3802,3796,3790,3784,3777,3771,3765,3759,3753,3747,3741,3736,3730,3724,3718,3712,3707,3701,3695,3690,3684,3679,3673,3667,3662,3657,3651,3646,3640,3635,3630,3624,3619,3614,3609,3603,3598,3593,3588,3583,3578,3573,3568,3563,3558,3553,3548,3543,3538,3533,3529,3524,3519,3514,3510,3505,3500,3496,3491,3486,3482,3477,3473,3468,3463,3459,3455,3450,3446,3441,3437,3432,3428,3424,3419,3415,3411,3407,3402,3398,3394,3390,3386,3381,3377,3373,3369,3365,3361,3357,3353,3349,3345,3341,3337,3333,3329,3325,3321,3318,3314,3310,3306,3302,3298,3295,3291,3287,3283,3280,3276,3272,3269,3265,3261,3258,3254,3251,3247,3243,3240,3236,3233,3229,3226,3222,3219,3215,3212,3208,3205,3202,3198,3195,3192,3188,3185,3182,3178,3175,3172,3168,3165,3162,3159,3155,3152,3149,3146,3143,3139,3136,3133,3130,3127,3124,3121,3118,3115,3111,3108,3105,3102,3099,3096,3093,3090,3087,3084,3081,3079,3076,3073,3070,3067,3064,3061,3058,3055,3052,3050,3047,3044,3041,3038,3036,3033,3030,3027,3025,3022,3019,3016,3014,3011,3008,3005,3003,3000,2997,2995,2992,2990,2987,2984,2982,2979,2976,2974,2971,2969,2966,2964,2961,2959,2956,2954,2951,2949,2946,2944,2941,2939,2936,2934,2931,2929,2926,2924,2922,2919,2917,2914,2912,2910,2907,2905,2902,2900,2898,2895,2893,2891,2888,2886,2884,2882,2879,2877,2875,2872,2870,2868,2866,2863,2861,2859,2857,2855,2852,2850,2848,2846,2844,2841,2839,2837,2835,2833,2831,2829,2826,2824,2822,2820,2818,2816,2814,2812,2810,2808,2805,2803,2801,2799,2797,2795,2793,2791,2789,2787,2785,2783,2781,2779,2777,2775,2773,2771,2769,2767,2765,2763,2761,2760,2758,2756,2754,2752,2750,2748,2746,2744,2742,2740,2739,2737,2735,2733,2731,2729,2727,2726,2724,2722,2720,2718,2716,2715,2713,2711,2709,2707,2706,2704,2702,2700,2698,2697,2695,2693,2691,2690,2688,2686,2684,2683,2681,2679,2677,2676,2674,2672,2671,2669,2667,2666,2664,2662,2660,2659,2657,2655,2654,2652,2650,2649,2647,2646,2644,2642,2641,2639,2637,2636,2634,2633,2631,2629,2628,2626,2625,2623,2621,2620,2618,2617,2615,2614,2612,2610,2609,2607,2606,2604,2603,2601,2600,2598,2597,2595,2594,2592,2591,2589,2588,2586,2585,2583,2582,2580,2579,2577,2576,2574,2573,2571,2570,2568,2567,2565,2564,2563,2561,2560,2558,2557,2555,2554,2553,2551,2550,2548,2547,2546,2544,2543,2541,2540,2539,2537,2536,2534,2533,2532,2530,2529,2528,2526,2525,2523,2522,2521,2519,2518,2517,2515,2514,2513,2511,2510,2509,2507,2506,2505,2503,2502,2501,2500,2498,2497,2496,2494,2493,2492,2491,2489,2488,2487,2485,2484,2483,2482,2480,2479,2478,2477,2475,2474,2473,2472,2470,2469,2468,2467,2465,2464,2463,2462,2460,2459,2458,2457,2456,2454,2453,2452,2451,2450,2448,2447,2446,2445,2444,2442,2441,2440,2439,2438,2437,2435,2434,2433,2432,2431,2430,2428,2427,2426,2425,2424,2423,2422,2420,2419,2418,2417,2416,2415,2414,2412,2411,2410,2409,2408,2407,2406,2405,2404,2402,2401,2400,2399,2398,2397,2396,2395,2394,2393,2391,2390,2389,2388,2387,2386,2385,2384,2383,2382,2381,2380,2379,2378,2376,2375,2374,2373,2372,2371,2370,2369,2368,2367,2366,2365,2364,2363,2362,2361,2360,2359,2358,2357,2356,2355,2354,2353,2352,2351,2350,2349,2348,2347,2346,2345,2344,2343,2342,2341,2340,2339,2338,2337,2336,2335,2334,2333,2332,2331,2330,2329,2328,2327,2326,2325,2324,2323,2322,2321,2320,2319,2318,2317,2316,2316,2315,2314,2313,2312,2311,2310,2309,2308,2307,2306,2305,2304,2303,2302,2302,2301,2300,2299,2298,2297,2296,2295,2294,2293,2292,2291,2291,2290,2289,2288,2287,2286,2285,2284,2283,2282,2282,2281,2280,2279,2278,2277,2276,2275,2275,2274,2273,2272,2271,2270,2269,2268,2268,2267,2266,2265,2264,2263,2262,2262,2261,2260,2259,2258,2257,2256,2256,2255,2254,2253,2252,2251,2251,2250,2249,2248,2247,2246,2246,2245,2244,2243,2242,2241,2241,2240,2239,2238,2237,2237,2236,2235,2234,2233,2232,2232,2231,2230,2229,2228,2228,2227,2226,2225,2224,2224,2223,2222,2221,2220,2220,2219,2218,2217,2217,2216,2215,2214,2213,2213,2212,2211,2210,2210,2209,2208,2207,2206,2206,2205,2204,2203,2203,2202,2201,2200,2200,2199,2198,2197,2197,2196,2195,2194,2194,2193,2192,2191,2191,2190,2189,2188,2188,2187,2186,2185,2185,2184,2183,2182,2182,2181,2180,2180,2179,2178,2177,2177,2176,2175,2174,2174,2173,2172,2172,2171,2170,2169,2169,2168,2167,2167,2166,2165,2164,2164,2163,2162,2162,2161,2160,2160,2159,2158,2157,2157,2156,2155,2155,2154,2153,2153,2152,2151,2151,2150,2149,2148,2148,2147,2146,2146,2145,2144,2144,2143,2142,2142,2141,2140,2140,2139,2138,2138,2137,2136,2136,2135,2134,2134,2133,2132,2132,2131,2130,2130,2129,2128,2128,2127,2126,2126,2125,2124,2124,2123,2123,2122,2121,2121,2120,2119,2119,2118,2117,2117,2116,2115,2115,2114,2114,2113,2112,2112,2111,2110,2110,2109,2109,2108,2107,2107,2106,2105,2105,2104,2104,2103,2102,2102,2101,2100,2100,2099,2099,2098,2097,2097,2096,2095,2095,2094,2094,2093,2092,2092,2091,2091,2090,2089,2089,2088,2088,2087,2086,2086,2085,2085,2084,2083,2083,2082,2082,2081,2080,2080,2079,2079,2078,2078,2077,2076,2076,2075,2075,2074,2073,2073,2072,2072,2071,2070,2070,2069,2069,2068,2068,2067,2066,2066,2065,2065,2064,2064,2063,2062,2062,2061,2061,2060,2060,2059,2058,2058,2057,2057,2056,2056,2055,2055,2054,2053,2053,2052,2052,2051,2051,2050,2050,2049,2048,2048,2047,2047,2046,2046,2045,2045,2044,2044,2043,2042,2042,2041,2041,2040,2040,2039,2039,2038,2038,2037,2036,2036,2035,2035,2034,2034,2033,2033,2032,2032,2031,2031,2030,2030,2029,2028,2028,2027,2027,2026,2026,2025,2025,2024,2024,2023,2023,2022,2022,2021,2021,2020,2020,2019,2019,2018,2018,2017,2017,2016,2015,2015,2014,2014,2013,2013,2012,2012,2011,2011,2010,2010,2009,2009,2008,2008,2007,2007,2006,2006,2005,2005,2004,2004,2003,2003,2002,2002,2001,2001,2000,2000,1999,1999,1998,1998,1997,1997,1996,1996,1995,1995,1994,1994,1993,1993,1993,1992,1992,1991,1991,1990,1990,1989,1989,1988,1988,1987,1987,1986,1986,1985,1985,1984,1984,1983,1983,1982,1982,1981,1981,1981,1980,1980,1979,1979,1978,1978,1977,1977,1976,1976,1975,1975,1974,1974,1973,1973,1973,1972,1972,1971,1971,1970,1970,1969,1969,1968,1968,1967,1967,1967,1966,1966,1965,1965,1964,1964,1963,1963,1962,1962,1962,1961,1961,1960,1960,1959,1959,1958,1958,1958,1957,1957,1956,1956,1955,1955,1954,1954,1954,1953,1953,1952,1952,1951,1951,1950,1950,1950,1949,1949,1948,1948,1947,1947,1946,1946,1946,1945,1945,1944,1944,1943,1943,1943,1942,1942,1941,1941,1940,1940,1940,1939,1939,1938,1938,1937,1937,1937,1936,1936,1935,1935,1934,1934,1934,1933,1933,1932,1932,1931,1931,1931,1930,1930,1929,1929,1929,1928,1928,1927,1927,1926,1926,1926,1925,1925,1924,1924,1924,1923,1923,1922,1922,1921,1921,1921,1920,1920,1919,1919,1919,1918,1918,1917,1917,1917,1916,1916,1915,1915,1915,1914,1914,1913,1913,1913,1912,1912,1911,1911,1911,1910,1910,1909,1909,1909,1908,1908,1907,1907,1907,1906,1906,1905,1905,1905,1904,1904,1903,1903,1903,1902,1902,1901,1901,1901,1900,1900,1900,1899,1899,1898,1898,1898,1897,1897,1896,1896,1896,1895,1895,1894,1894,1894,1893,1893,1893,1892,1892,1891,1891,1891,1890,1890,1890,1889,1889,1888,1888,1888,1887,1887,1886,1886,1886,1885,1885,1885,1884,1884,1883,1883,1883,1882,1882,1882,1881,1881,1881,1880,1880,1879,1879,1879,1878,1878,1878,1877,1877,1876,1876,1876,1875,1875,1875,1874,1874,1874,1873,1873,1872,1872,1872,1871,1871,1871,1870,1870,1870,1869,1869,1868,1868,1868,1867,1867,1867,1866,1866,1866,1865,1865,1865,1864,1864,1863,1863,1863,1862,1862,1862,1861,1861,1861,1860,1860,1860,1859,1859,1859,1858,1858,1857,1857,1857,1856,1856,1856,1855,1855,1855,1854,1854,1854,1853,1853,1853,1852,1852,1852,1851,1851,1851,1850,1850,1850,1849,1849,1848,1848,1848,1847,1847,1847,1846,1846,1846,1845,1845,1845,1844,1844,1844,1843,1843,1843,1842,1842,1842,1841,1841,1841,1840,1840,1840,1839,1839,1839,1838,1838,1838,1837,1837,1837,1836,1836,1836,1835,1835,1835,1834,1834,1834,1833,1833,1833,1832,1832,1832,1831,1831,1831,1830,1830,1830,1829,1829,1829,1829,1828,1828,1828,1827,1827,1827,1826,1826,1826,1825,1825,1825,1824,1824,1824,1823,1823,1823,1822,1822,1822,1821,1821,1821,1820,1820,1820,1820,1819,1819,1819,1818,1818,1818,1817,1817,1817,1816,1816,1816,1815,1815,1815,1815,1814,1814  },
  {
    360000,270000,216000,180000,154286,135000,120000,108000,98182,90000,83077,77143,72000,67500,63529,60000,56842,54000,51429,49091,46957,45000,43200,41538,40000,38571,37241,36000,34839,33750,32727,31765,30857,30000,29189,28421,27692,27000,26341,25714,25116,24545,24000,23478,22979,22500,22041,21600,21176,20769,20377,20000,19636,19286,18947,18621,18305,18000,17705,17419,17143,16875,16615,16364,16119,15882,15652,15429,15211,15000,14795,14595,14400,14211,14026,13846,13671,13500,13333,13171,13012,12857,12706,12558,12414,12273,12135,12000,11868,11739,11613,11489,11368,11250,11134,11020,10909,10800,10693,10588,10485,10385,10286,10189,10093,10000,9908,9818,9730,9643,9558,9474,9391,9310,9231,9153,9076,9000,8926,8852,8780,8710,8640,8571,8504,8438,8372,8308,8244,8182,8120,8060,8000,7941,7883,7826,7770,7714,7660,7606,7552,7500,7448,7397,7347,7297,7248,7200,7152,7105,7059,7013,6968,6923,6879,6835,6792,6750,6708,6667,6626,6585,6545,6506,6467,6429,6391,6353,6316,6279,6243,6207,6171,6136,6102,6067,6034,6000,5967,5934,5902,5870,5838,5806,5775,5745,5714,5684,5654,5625,5596,5567,5538,5510,5482,5455,5427,5400,5373,5347,5320,5294,5268,5243,5217,5192,5167,5143,5118,5094,5070,5047,5023,5000,4977,4954,4932,4909,4887,4865,4843,4821,4800,4779,4758,4737,4716,4696,4675,4655,4635,4615,4596,4576,4557,4538,4519,4500,4481,4463,4444,4426,4408,4390,4372,4355,4337,4320,4303,4286,4269,4252,4235,4219,4202,4186,4170,4154,4138,4122,4106,4091,4075,4060,4045,4030,4015,4000,3985,3971,3956,3942,3927,3913,3899,3885,3871,3857,3843,3830,3816,3803,3789,3776,3763,3750,3737,3724,3711,3699,3686,3673,3661,3649,3636,3624,3612,3600,3588,3576,3564,3553,3541,3529,3518,3506,3495,3484,3473,3462,3450,3439,3429,3418,3407,3396,3386,3375,3364,3354,3344,3333,3323,3313,3303,3293,3283,3273,3263,3253,3243,3234,3224,3214,3205,3195,3186,3176,3167,3158,3149,3140,3130,3121,3112,3103,3095,3086,3077,3068,3059,3051,3042,3034,3025,3017,3008,3000,2992,2983,2975,2967,2959,2951,2943,2935,2927,2919,2911,2903,2895,2888,2880,2872,2865,2857,2850,2842,2835,2827,2820,2813,2805,2798,2791,2784,2776,2769,2762,2755,2748,2741,2734,2727,2720,2714,2707,2700,2693,2687,2680,2673,2667,2660,2654,2647,2641,2634,2628,2621,2615,2609,2602,2596,2590,2584,2578,2571,2565,2559,2553,2547,2541,2535,2529,2523,2517,2512,2506,2500,2494,2488,2483,2477,2471,2466,2460,2455,2449,2443,2438,2432,2427,2422,2416,2411,2405,2400,2395,2389,2384,2379,2374,2368,2363,2358,2353,2348,2343,2338,2333,2328,2323,2318,2313,2308,2303,2298,2293,2288,2283,2278,2274,2269,2264,2259,2255,2250,2245,2241,2236,2231,2227,2222,2218,2213,2209,2204,2200,2195,2191,2186,2182,2177,2173,2169,2164,2160,2156,2151,2147,2143,2139,2134,2130,2126,2122,2118,2114,2109,2105,2101,2097,2093,2089,2085,2081,2077,2073,2069,2065,2061,2057,2053,2049,2045,2042,2038,2034,2030,2026,2022,2019,2015,2011,2007,2004,2000,1996,1993,1989,1985,1982,1978,1974,1971,1967,1964,1960,1957,1953,1949,1946,1942,1939,1935,1932,1929,1925,1922,1918,1915,1912,1908,1905,1901,1898,1895,1891,1888,1885,1882,1878,1875,1872,1869,1865,1862,1859,1856,1852,1849,1846,1843,1840,1837,1834,1831,1827,1824,1821,1818,1815,1812,1809,1806,1803,1800,1797,1794,1791,1788,1785,1782,1779,1776,1773,1770,1768,1765,1762,1759,1756,1753,1750,1748,1745,1742,1739,1736,1734,1731,1728,1725,1722,1720,1717,1714,1712,1709,1706,1703,1701,1698,1695,1693,1690,1688,1685,1682,1680,1677,1674,1672,1669,1667,1664,1662,1659,1656,1654,1651,1649,1646,1644,1641,1639,1636,1634,1631,1629,1627,1624,1622,1619,1617,1614,1612,1610,1607,1605,1602,1600,1598,1595,1593,1591,1588,1586,1584,1581,1579,1577,1574,1572,1570,1567,1565,1563,1561,1558,1556,1554,1552,1549,1547,1545,1543,1541,1538,1536,1534,1532,1530,1528,1525,1523,1521,1519,1517,1515,1513,1510,1508,1506,1504,1502,1500,1498,1496,1494,1492,1490,1488,1486,1484,1481,1479,1477,1475,1473,1471,1469,1467,1465,1463,1461,1459,1457,1456,1454,1452,1450,1448,1446,1444,1442,1440,1438,1436,1434,1432,1430,1429,1427,1425,1423,1421,1419,1417,1415,1414,1412,1410,1408,1406,1404,1403,1401,1399,1397,1395,1394,1392,1390,1388,1386,1385,1383,1381,1379,1378,1376,1374,1372,1371,1369,1367,1365,1364,1362,1360,1358,1357,1355,1353,1352,1350,1348,1347,1345,1343,1342,1340,1338,1337,1335,1333,1332,1330,1328,1327,1325,1324,1322,1320,1319,1317,1315,1314,1312,1311,1309,1308,1306,1304,1303,1301,1300,1298,1297,1295,1293,1292,1290,1289,1287,1286,1284,1283,1281,1280,1278,1277,1275,1274,1272,1271,1269,1268,1266,1265,1263,1262,1260,1259,1257,1256,1254,1253,1251,1250,1249,1247,1246,1244,1243,1241,1240,1239,1237,1236,1234,1233,1231,1230,1229,1227,1226,1224,1223,1222,1220,1219,1218,1216,1215,1213,1212,1211,1209,1208,1207,1205,1204,1203,1201,1200,1199,1197,1196,1195,1193,1192,1191,1189,1188,1187,1186,1184,1183,1182,1180,1179,1178,1176,1175,1174,1173,1171,1170,1169,1168,1166,1165,1164,1163,1161,1160,1159,1158,1156,1155,1154,1153,1151,1150,1149,1148,1146,1145,1144,1143,1142,1140,1139,1138,1137,1136,1134,1133,1132,1131,1130,1129,1127,1126,1125,1124,1123,1121,1120,1119,1118,1117,1116,1115,1113,1112,1111,1110,1109,1108,1107,1105,1104,1103,1102,1101,1100,1099,1098,1096,1095,1094,1093,1092,1091,1090,1089,1088,1087,1085,1084,1083,1082,1081,1080,1079,1078,1077,1076,1075,1074,1072,1071,1070,1069,1068,1067,1066,1065,1064,1063,1062,1061,1060,1059,1058,1057,1056,1055,1054,1053,1052,1051,1050,1049,1048,1047,1045,1044,1043,1042,1041,1040,1039,1038,1037,1036,1035,1034,1033,1033,1032,1031,1030,1029,1028,1027,1026,1025,1024,1023,1022,1021,1020,1019,1018,1017,1016,1015,1014,1013,1012,1011,1010,1009,1008,1007,1007,1006,1005,1004,1003,1002,1001,1000,999,998,997,996,995,994,994,993,992,991,990,989,988,987,986,985,985,984,983,982,981,980,979,978,977,976,976,975,974,973,972,971,970,969,969,968,967,966,965,964,963,963,962,961,960,959,958,957,957,956,955,954,953,952,952,951,950,949,948,947,947,946,945,944,943,942,942,941,940,939,938,938,937,936,935,934,933,933,932,931,930,929,929,928,927,926,925,925,924,923,922,922,921,920,919,918,918,917,916,915,914,914,913,912,911,911,910,909,908,908,907,906,905,905,904,903,902,902,901,900,899,899,898,897,896,896,895,894,893,893,892,891,890,890,889,888,887,887,886,885,885,884,883,882,882,881,880,879,879,878,877,877,876,875,874,874,873,872,872,871,870,870,869,868,867,867,866,865,865,864,863,863,862,861,861,860,859,859,858,857,856,856,855,854,854,853,852,852,851,850,850,849,848,848,847,846,846,845,844,844,843,842,842,841,840,840,839,839,838,837,837,836,835,835,834,833,833,832,831,831,830,829,829,828,828,827,826,826,825,824,824,823,823,822,821,821,820,819,819,818,818,817,816,816,815,814,814,813,813,812,811,811,810,810,809,808,808,807,807,806,805,805,804,804,803,802,802,801,801,800,799,799,798,798,797,796,796,795,795,794,794,793,792,792,791,791,790,789,789,788,788,787,787,786,785,785,784,784,783,783,782,781,781,780,780,779,779,778,778,777,776,776,775,775,774,774,773,773,772,771,771,770,770,769,769,768,768,767,767,766,765,765,764,764,763,763,762,762,761,761,760,759,759,758,758,757,757,756,756,755,755,754,754,753,753,752,752,751,751,750,749,749,748,748,747,747,746,746,745,745,744,744,743,743,742,742,741,741,740,740,739,739,738,738,737,737,736,736,735,735,734,734,733,733,732,732,731,731,730,730,729,729,728,728,727,727,726,726,725,725,724,724,723,723,722,722,721,721,720,720,720,719,719,718,718,717,717,716,716,715,715,714,714,713,713,712,712,711,711,711,710,710,709,709,708,708,707,707,706,706,705,705,705,704,704,703,703,702,702,701,701,700,700,699,699,699,698,698,697,697,696,696,695,695,695,694,694,693,693,692,692,691,691,691,690,690,689,689,688,688,687,687,687,686,686,685,685,684,684,684,683,683,682,682,681,681,681,680,680,679,679,678,678,678,677,677,676,676,675,675,675,674,674,673,673,672,672,672,671,671,670,670,670,669,669,668,668,667,667,667,666,666,665,665,665,664,664,663,663,663,662,662,661,661,661,660,660,659,659,659,658,658,657,657,657,656,656,655,655,655,654,654,653,653,653,652,652,651,651,651,650,650,649,649,649,648,648,647,647,647,646,646,646,645,645,644,644,644,643,643,642,642,642,641,641,641,640,640,639,639,639,638,638,638,637,637,636,636,636,635,635,635,634,634,633,633,633,632,632,632,631,631,630,630,630,629,629,629,628,628,628,627,627,626,626,626,625,625,625,624,624,624,623,623,622,622,622,621,621,621,620,620,620,619,619,619,618,618,617,617,617,616,616,616,615,615,615,614,614,614,613,613,613,612,612,612,611,611,611,610,610,609,609,609,608,608,608,607,607,607,606,606,606,605,605,605,604,604,604,603,603,603,602,602,602,601,601,601,600,600,600,599,599,599,598,598,598,597,597,597,596,596,596,595,595,595,594,594,594,593,593,593,592,592,592,591,591,591,590,590,590,590,589,589,589,588,588,588,587,587,587,586,586,586,585,585,585,584,584,584,583,583,583,583,582,582,582,581,581,581,580,580,580,579,579,579,578,578,578,578,577,577,577,576,576,576,575,575,575,574,574,574,574,573,573,573,572,572,572,571,571,571,571,570,570,570,569,569,569,568  },
  {
    1050903,784314,624390,517799,441684,384615,340245,304762,275743,251572,231130,213618,198450,185185,173489,163099,153809,145455,137901,131040,124781,119048,113778,108918,104422,100251,96371,92754,89373,86207,83236,80442,77812,75330,72984,70765,68662,66667,64771,62967,61250,59613,58050,56557,55130,53763,52455,51200,49996,48840,47729,46661,45633,44643,43689,42769,41882,41026,40198,39399,38626,37879,37155,36455,35776,35119,34481,33862,33262,32680,32114,31564,31030,30511,30006,29515,29037,28571,28118,27677,27247,26828,26419,26020,25632,25253,24882,24521,24168,23824,23487,23158,22837,22523,22215,21915,21621,21333,21052,20777,20507,20243,19984,19731,19483,19240,19002,18768,18539,18315,18095,17879,17667,17460,17256,17056,16859,16667,16477,16292,16109,15930,15754,15581,15411,15244,15080,14918,14760,14604,14451,14300,14151,14006,13862,13721,13582,13445,13311,13178,13048,12920,12794,12669,12547,12426,12307,12190,12075,11962,11850,11740,11631,11524,11419,11315,11212,11111,11012,10913,10816,10721,10627,10534,10442,10352,10263,10175,10088,10003,9918,9835,9752,9671,9591,9512,9434,9357,9281,9205,9131,9058,8986,8914,8844,8774,8705,8637,8570,8503,8438,8373,8309,8246,8183,8121,8060,8000,7940,7881,7823,7765,7709,7652,7597,7541,7487,7433,7380,7327,7275,7224,7173,7123,7073,7023,6975,6926,6879,6831,6785,6739,6693,6648,6603,6558,6515,6471,6428,6386,6344,6302,6261,6220,6179,6139,6100,6061,6022,5983,5945,5908,5870,5833,5797,5760,5724,5689,5654,5619,5584,5550,5516,5482,5449,5416,5384,5351,5319,5287,5256,5225,5194,5163,5133,5103,5073,5043,5014,4985,4956,4928,4900,4872,4844,4816,4789,4762,4735,4709,4682,4656,4630,4604,4579,4554,4529,4504,4479,4455,4431,4407,4383,4359,4336,4313,4290,4267,4244,4222,4199,4177,4155,4133,4112,4090,4069,4048,4027,4006,3986,3965,3945,3925,3905,3885,3866,3846,3827,3808,3789,3770,3751,3732,3714,3695,3677,3659,3641,3624,3606,3588,3571,3554,3537,3520,3503,3486,3469,3453,3436,3420,3404,3388,3372,3356,3340,3325,3309,3294,3279,3263,3248,3233,3219,3204,3189,3175,3160,3146,3132,3117,3103,3089,3076,3062,3048,3035,3021,3008,2994,2981,2968,2955,2942,2929,2917,2904,2891,2879,2866,2854,2842,2829,2817,2805,2793,2781,2770,2758,2746,2735,2723,2712,2700,2689,2678,2667,2656,2645,2634,2623,2612,2601,2591,2580,2569,2559,2549,2538,2528,2518,2508,2498,2487,2478,2468,2458,2448,2438,2429,2419,2409,2400,2390,2381,2372,2362,2353,2344,2335,2326,2317,2308,2299,2290,2281,2273,2264,2255,2247,2238,2230,2221,2213,2205,2196,2188,2180,2172,2164,2155,2147,2139,2132,2124,2116,2108,2100,2093,2085,2077,2070,2062,2055,2047,2040,2032,2025,2018,2010,2003,1996,1989,1982,1975,1968,1961,1954,1947,1940,1933,1926,1920,1913,1906,1900,1893,1886,1880,1873,1867,1860,1854,1848,1841,1835,1829,1822,1816,1810,1804,1798,1792,1785,1779,1773,1767,1762,1756,1750,1744,1738,1732,1727,1721,1715,1709,1704,1698,1693,1687,1681,1676,1670,1665,1660,1654,1649,1643,1638,1633,1628,1622,1617,1612,1607,1602,1596,1591,1586,1581,1576,1571,1566,1561,1556,1552,1547,1542,1537,1532,1527,1523,1518,1513,1508,1504,1499,1494,1490,1485,1481,1476,1472,1467,1463,1458,1454,1449,1445,1441,1436,1432,1428,1423,1419,1415,1410,1406,1402,1398,1394,1390,1385,1381,1377,1373,1369,1365,1361,1357,1353,1349,1345,1341,1337,1333,1329,1326,1322,1318,1314,1310,1307,1303,1299,1295,1292,1288,1284,1281,1277,1273,1270,1266,1262,1259,1255,1252,1248,1245,1241,1238,1234,1231,1227,1224,1221,1217,1214,1210,1207,1204,1200,1197,1194,1190,1187,1184,1181,1177,1174,1171,1168,1165,1162,1158,1155,1152,1149,1146,1143,1140,1137,1134,1131,1128,1125,1122,1119,1116,1113,1110,1107,1104,1101,1098,1095,1092,1089,1086,1084,1081,1078,1075,1072,1070,1067,1064,1061,1058,1056,1053,1050,1048,1045,1042,1039,1037,1034,1032,1029,1026,1024,1021,1018,1016,1013,1011,1008,1006,1003,1001,998,996,993,991,988,986,983,981,978,976,973,971,969,966,964,961,959,957,954,952,950,947,945,943,940,938,936,934,931,929,927,925,922,920,918,916,913,911,909,907,905,903,900,898,896,894,892,890,888,886,883,881,879,877,875,873,871,869,867,865,863,861,859,857,855,853,851,849,847,845,843,841,839,837,835,833,832,830,828,826,824,822,820,818,816,815,813,811,809,807,805,804,802,800,798,796,795,793,791,789,788,786,784,782,781,779,777,775,774,772,770,769,767,765,764,762,760,758,757,755,754,752,750,749,747,745,744,742,741,739,737,736,734,733,731,729,728,726,725,723,722,720,719,717,716,714,713,711,710,708,707,705,704,702,701,699,698,696,695,693,692,690,689,688,686,685,683,682,680,679,678,676,675,673,672,671,669,668,667,665,664,662,661,660,658,657,656,654,653,652,650,649,648,646,645,644,643,641,640,639,637,636,635,634,632,631,630,629,627,626,625,624,622,621,620,619,617,616,615,614,613,611,610,609,608,607,605,604,603,602,601,600,598,597,596,595,594,593,591,590,589,588,587,586,585,584,582,581,580,579,578,577,576,575,574,573,571,570,569,568,567,566,565,564,563,562,561,560,559,558,557,556,554,553,552,551,550,549,548,547,546,545,544,543,542,541,540,539,538,537,536,535,534,533,532,531,530,529,528,528,527,526,525,524,523,522,521,520,519,518,517,516,515,514,513,512,512,511,510,509,508,507,506,505,504,503,502,502,501,500,499,498,497,496,495,495,494,493,492,491,490,489,488,488,487,486,485,484,483,483,482,481,480,479,478,478,477,476,475,474,473,473,472,471,470,469,469,468,467,466,465,465,464,463,462,461,461,460,459,458,457,457,456,455,454,454,453,452,451,451,450,449,448,448,447,446,445,445,444,443,442,442,441,440,439,439,438,437,436,436,435,434,434,433,432,431,431,430,429,429,428,427,427,426,425,424,424,423,422,422,421,420,420,419,418,418,417,416,416,415,414,414,413,412,412,411,410,410,409,408,408,407,406,406,405,404,404,403,402,402,401,401,400,399,399,398,397,397,396,396,395,394,394,393,392,392,391,391,390,389,389,388,388,387,386,386,385,385,384,383,383,382,382,381,380,380,379,379,378,377,377,376,376,375,375,374,373,373,372,372,371,371,370,369,369,368,368,367,367,366,366,365,364,364,363,363,362,362,361,361,360,360,359,358,358,357,357,356,356,355,355,354,354,353,353,352,352,351,350,350,349,349,348,348,347,347,346,346,345,345,344,344,343,343,342,342,341,341,340,340,339,339,338,338,337,337,336,336,335,335,334,334,333,333,332,332,332,331,331,330,330,329,329,328,328,327,327,326,326,325,325,324,324,324,323,323,322,322,321,321,320,320,319,319,319,318,318,317,317,316,316,315,315,315,314,314,313,313,312,312,311,311,311,310,310,309,309,308,308,308,307,307,306,306,305,305,305,304,304,303,303,302,302,302,301,301,300,300,300,299,299,298,298,298,297,297,296,296,296,295,295,294,294,294,293,293,292,292,292,291,291,290,290,290,289,289,288,288,288,287,287,286,286,286,285,285,285,284,284,283,283,283,282,282,282,281,281,280,280,280,279,279,279,278,278,277,277,277,276,276,276,275,275,275,274,274,273,273,273,272,272,272,271,271,271,270,270,270,269,269,269,268,268,268,267,267,266,266,266,265,265,265,264,264,264,263,263,263,262,262,262,261,261,261,260,260,260,259,259,259,258,258,258,257,257,257,256,256,256,255,255,255,254,254,254,254,253,253,253,252,252,252,251,251,251,250,250,250,249,249,249,248,248,248,248,247,247,247,246,246,246,245,245,245,244,244,244,244,243,243,243,242,242,242,241,241,241,241,240,240,240,239,239,239,239,238,238,238,237,237,237,237,236,236,236,235,235,235,235,234,234,234,233,233,233,233,232,232,232,231,231,231,231,230,230,230,229,229,229,229,228,228,228,228,227,227,227,226,226,226,226,225,225,225,225,224,224,224,224,223,223,223,222,222,222,222,221,221,221,221,220,220,220,220,219,219,219,219,218,218,218,218,217,217,217,217,216,216,216,216,215,215,215,215,214,214,214,214,213,213,213,213,212,212,212,212,211,211,211,211,210,210,210,210,209,209,209,209,208,208,208,208,208,207,207,207,207,206,206,206,206,205,205,205,205,204,204,204,204,204,203,203,203,203,202,202,202,202,201,201,201,201,201,200,200,200,200,199,199,199,199,199,198,198,198,198,197,197,197,197,197,196,196,196,196,196,195,195,195,195,194,194,194,194,194,193,193,193,193,193,192,192,192,192,191,191,191,191,191,190,190,190,190,190,189,189,189,189,189,188,188,188,188,188,187,187,187,187,187,186,186,186,186,186,185,185,185,185,185,184,184,184,184,184,183,183,183,183,183,182,182,182,182,182,181,181,181,181,181,180,180,180,180,180,179,179,179,179,179,179,178,178,178,178,178,177,177,177,177,177,176,176,176,176,176,176,175,175,175,175,175,174,174,174,174,174,174,173,173,173,173,173,172,172,172,172,172,172,171,171,171,171,171,171,170,170,170,170,170,169,169,169,169,169,169,168,168,168,168,168,168,167,167,167,167,167,167,166,166,166,166,166,166,165,165,165,165,165,164,164,164,164,164,164,164,163,163,163,163,163,163,162,162,162,162,162,162,161,161,161,161,161,161,160  }
};

void Sliding_voltage(float data, TChannelData* channelData)
{
  // Sliding voltage for the voltages and the voltages sqr as well as its total
  // Voltage sqr is used for the calculation of voltageRMS
  // Voltage is used to find the zero crossing later on for the frequency
  OS_DisableInterrupts();
  channelData->totalVoltageSqr += (data*data);
  channelData->totalVoltageSqr -= channelData->voltageSqr[0];
  for(int i = 1; i < 16; i++)
  {
    channelData->voltage[i-1] = channelData->voltage[i];
    channelData->voltageSqr[i-1] = channelData->voltage[i];
  }
  channelData->voltage[15] = data;
  channelData->voltageSqr[15] = data*data;
  OS_EnableInterrupts();
}


float Real_RMS(TChannelData* channelData)
{
  // Calculates the voltage RMS using the totalVoltageSqr
  OS_DisableInterrupts();
  float SqRootRMS = ((channelData->totalVoltageSqr)/16); // Dividing the total of v^2 by the number of sample per period N = 16
  float voltageRMS = sqrt(SqRootRMS); // Using equation from math.h
  OS_EnableInterrupts();
  return voltageRMS;
}


float Current_RMS(float voltageRMS)
{
  return (voltageRMS*0.350); // 350mV RMS = 1 A RMS (project notes)
}


uint32_t Calculate_TripGoal(float currentRMS)
{
  uint16_t index = (uint16_t)(currentRMS*100);
  return TripTimes[Current_Charac][index-103]; // Minusing 103 because not using current under 1.03 A
}


bool Zero_Crossings(float sample[], TCrossing* crossing)
{
  OS_DisableInterrupts();
  crossing->crossing1 = crossing->crossing2; // to check if they have been assigned later on, if they have, they shouldn't be equal
  for (uint8_t i = 0; i < 16; i++)
  {
    if (((sample[i] > 0) && (sample[i+1] < 0)) || ((sample[i] < 0) && (sample[i+1] > 0)))
    {
      crossing->crossing1 = i;
      break;
    }
  }

  for (uint8_t i = crossing->crossing1 + 2; i < 16; i++)
  {
    if (((sample[i] > 0) && (sample[i+1] < 0)) || ((sample[i] < 0) && (sample[i+1] > 0)))
    {
      crossing->crossing2 = i;
      break;
    }
  }

  if(crossing->crossing1 == crossing->crossing2)
  {
    return false;
  }
  else
  {
    return true;
  }

}


float Calculate_Frequency(TCrossing* crossing)
{
  OS_DisableInterrupts();
  float period = 2*(crossing->crossing2 - crossing->crossing1);
  period = (period*1.25)/1000;
  float frequency = (1/period);
  if (frequency > 47.5 && frequency < 52.5)
  {
    PIT_Set((uint32_t) (period*1e9), true, 0);
    OS_EnableInterrupts();
    return frequency;
  }
  else
  {
    OS_EnableInterrupts();
    return 0; // Return 0 if the frequency is not between 47.5 and 52.5
  }

}



