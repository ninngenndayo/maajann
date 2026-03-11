typedef struct {
        uint8_t type;      // 0–33
        uint8_t id;        // 0–3
        uint32_t flags;    // 赤・特殊
} Tile;

typedef struct {
        Tile tiles[136];
} TilePool;

typedef struct {
        uint8_t order[136];   // tiles[] index
        uint8_t position;
} Wall;

typedef struct {
        uint8_t hand_index[14];
        uint8_t hand_size;

        uint8_t count[34];      // 射影（高速化用）

        uint8_t meld_index[16]; // ポン・チー牌index
        uint8_t meld_size;

        int score;
        uint8_t riichi;
} PlayerState;

typedef struct {
        uint8_t discard_index[24];
        uint8_t size;
} River;

typedef struct {
        uint32_t rule_flags;

        bool (*is_dora)(uint8_t tile_index);
        int  (*score_func)(void*);
} Rule;

typedef struct {
        uint8_t current_player;
        uint8_t turn_number;

        uint8_t dora_indicators[10];
        uint8_t dora_count;

        int honba;
        int kyotaku;
} RoundState;

typedef struct {
        Rule rule;

        TilePool tile_pool;
        Wall wall;

        PlayerState players[4];
        River rivers[4];

        RoundState round;
} Game;