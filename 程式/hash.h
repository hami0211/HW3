int hash17(int a,int len);
struct dnode **hash_insert(struct dnode **hTAB,int a[],int len);
void hash_find(struct dnode **hTAB,int len,int b[],int findlen);
void h_insert(struct dnode **hTab,int maxhash,int key);
void h_find(struct dnode **hTab,int maxhash,int key);
struct dnode *L_insert(struct dnode *L,int key);
void L_find(struct dnode *L,int key);