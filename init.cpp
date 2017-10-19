void init_bit_mask()
{
	memset(set_mask, 0ULL, sizeof(set_mask));
	memset(set_mask, 0ULL, sizeof(clear_mask));

	for(int i = 0; i < 64; i++)
	{
		set_mask[i] |= (1ULL << i);       // initailize 1 for given pos and elsewhere 0
		clear_mask[i] = ~set_mask[i];     // initailize 0 for given pos and elsewhere 1         
	}
}

void initsq120to64()
{
	int count = 0, sq;              // count will give value from 0 to 63

	for(int i = 0; i < board_square; i++)            // first assign all value 65 in 64 indexed base
		sq120tosq64[i] = 65;

	for(int i = 0; i < 64; i++)
		sq64tosq120[i] = 120;							// first assign all value 120 in 120 indexed base


	for(int i = rank_1; i <= rank_8; i++)
	{
		for(int j = file_a; j <= file_h; j++)
		{
			sq = FR2SQ(j, i);                      // first convert 120 indexed value
			sq64tosq120[count] = sq;               // store in 120 indexed base array at pos count (0 - 63) 
			sq120tosq64[sq] = count;               // store in 64 indexed base array at pos sq (0 - 119)
			count++;
		}
	}

}

void all_init()
{
	initsq120to64();
	init_bit_mask();	
}
