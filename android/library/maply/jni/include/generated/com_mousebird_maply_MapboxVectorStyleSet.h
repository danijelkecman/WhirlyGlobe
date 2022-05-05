/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_mousebird_maply_MapboxVectorStyleSet */

#ifndef _Included_com_mousebird_maply_MapboxVectorStyleSet
#define _Included_com_mousebird_maply_MapboxVectorStyleSet
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    setArealShaderNative
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_setArealShaderNative
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    stylesForFeature
 * Signature: (Lcom/mousebird/maply/AttrDictionary;Lcom/mousebird/maply/TileID;Ljava/lang/String;Lcom/mousebird/maply/RenderControllerInterface;)[Lcom/mousebird/maply/VectorStyle;
 */
JNIEXPORT jobjectArray JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_stylesForFeature
        (JNIEnv *, jobject, jobject attrs, jobject tileID, jstring featureName, jobject control);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    allStyles
 * Signature: ()[Lcom/mousebird/maply/VectorStyle;
 */
JNIEXPORT jobjectArray JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_allStyles
        (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    layerShouldDisplay
 * Signature: (Ljava/lang/String;Lcom/mousebird/maply/TileID;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_layerShouldDisplay
(JNIEnv *, jobject, jstring name, jobject tileID);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    styleForUUID
 * Signature: (JLcom/mousebird/maply/RenderControllerInterface;)Lcom/mousebird/maply/VectorStyle;
 */
JNIEXPORT jobject JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_styleForUUID
        (JNIEnv *, jobject, jlong uuid, jobject control);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    hasBackgroundStyle
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_hasBackgroundStyle
        (JNIEnv *env, jobject obj);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    backgroundColorForZoomNative
 * Signature: (D)I
 */
JNIEXPORT jint JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_backgroundColorForZoomNative
  (JNIEnv *, jobject, jdouble);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    getZoomSlot
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_getZoomSlot
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    setZoomSlot
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_setZoomSlot
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    getStyleInfo
 * Signature: ()[Lcom/mousebird/maply/AttrDictionary;
 */
JNIEXPORT jobjectArray JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_getStyleInfo
        (JNIEnv *, jobject, jfloat zoom);

JNIEXPORT void JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_setLayerVisible
        (JNIEnv *, jobject, jstring, jboolean);

JNIEXPORT jboolean JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_addSpritesNative
        (JNIEnv *, jobject, jstring, jlong, jint , jint);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    getSpriteInfoNative
 * Signature: (Ljava/lang/String;[I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_getSpriteInfoNative
        (JNIEnv *env, jobject obj, jstring nameStr, jintArray xywh);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    initialise
 * Signature: (Lcom/mousebird/maply/Scene;Lcom/mousebird/maply/CoordSystem;Lcom/mousebird/maply/VectorStyleSettings;Lcom/mousebird/maply/AttrDictionary;)V
 */
JNIEXPORT jboolean JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_initialise
  (JNIEnv *, jobject, jobject, jobject, jobject, jobject);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    dispose
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_dispose
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_MapboxVectorStyleSet
 * Method:    nativeInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_MapboxVectorStyleSet_nativeInit
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
