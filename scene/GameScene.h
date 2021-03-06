#pragma once

#include "Audio.h"
#include "DebugText.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <DirectXMath.h>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

  public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

  private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	DebugText* debugText_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>

	// BG（スプライト）
	uint32_t textureHandleBG_ = 0;
	Sprite* spriteBG_ = nullptr;

	// ビュープロジェクション
	ViewProjection viewProjection_;

	// ステージ
	uint32_t textureHandleStage_ = 0;
	Model* modelStage_ = nullptr;
	WorldTransform worldTransformStage_;

	// プレイヤー
	uint32_t textureHandlePlayer_ = 0;
	Model* modelPlayer_ = nullptr;
	WorldTransform worldTransformPlayer_;

	// ビ－ム
	uint32_t textureHandleBeam_ = 0;
	Model* modelBeam_ = nullptr;
	WorldTransform worldTransformBeam_;
	int beamFlag_ = 0; // ビーム存在フラグ（0:存在しない、1:存在する）

	// 敵
	uint32_t textureHandleEnemy_ = 0;
	Model* modelEnemy_ = nullptr;
	WorldTransform worldTransformEnemy_;
	int enemyFlag_ = 0; // 敵存在フラグ（0:存在しない、1:存在する）

	// サウンドデータハンドル
	// uint32_t soundDataHandle_ = 0;

	// 音声再生ハンドル
	// uint32_t voiceHandle_ = 0;

	//  値を表示したい変数
	// int32_t value_ = 0;

	int gameScore_ = 0;  // ゲームスコア
	int playerLife_ = 3; // プレイヤーライフ

	void PlayerUpdate();         // プレイヤー更新
	void BeamUpdate();           // ビーム更新
	void BeamMove();             // ビーム移動
	void BeamBorn();             // ビーム発生
	void EnemyUpdate();          // 敵更新
	void EnemyMove();            // 敵移動
	void EnemyBorn();            // 敵発生
	void Collision();            // 衝突判定
	void CollisionPlayerEnemy(); // 衝突判定（プレイヤーと敵）
	void CollisionBeamEnemy();   // 衝突判定（ビームと敵）
};
