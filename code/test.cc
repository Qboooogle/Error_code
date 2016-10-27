/*
*/

#include "Source.cc"
#define MAX_VARI 25
#define BIT_NUM 8

int main() {

    int vv[10000];
    int ss[10000];
    double nor[10000];
    double rr[10000];
    int ss0[10000];

    double err_bit_pro[51];
    double err_frame_pro[51];
    double N0[51];

    int index = 0;
    for (double variance = 0.5; variance <= MAX_VARI; variance += 0.5) {
        Source src = Source();
        N0[index] = (double)2 * variance * variance;

        while (src.GetErrorBitNum() <= 100000) {
            src.GetBitStr(vv, BIT_NUM);
            src.GetNormalSeq(nor, BIT_NUM);
            for (int i = 0; i < BIT_NUM; i++) {
                ss[i] = 2 * vv[i] - 1;
                rr[i] = (double)ss[i] + variance * nor[i];
                ss0[i] = rr[i] > 0 ? 1 : 0;
            }
            src.CountError(vv, ss0, BIT_NUM);
        }
        err_bit_pro[index] = (double)src.GetErrorBitNum() / (double)src.GetTotalBitNum();
        err_frame_pro[index] = (double)src.GetErrorFrameNum() / (double)src.GetTotalFrameNum();

        index++;
    }

    for (int i = 0; i < 50; i++)
        cout <<"  N0:" <<  N0[i] << "      err_bit_pro:" << err_bit_pro[i] << "      err_frame_pro:" << err_frame_pro[i] << endl;
        //cout <<  err_bit_pro[i]<< "      " << err_frame_pro[i]<<endl;

    return 0;
}

