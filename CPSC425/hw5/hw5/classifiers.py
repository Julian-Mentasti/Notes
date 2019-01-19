 #Starter code prepared by Borna Ghotbi for computer vision
 #based on MATLAB code by James Hay

'''This function will predict the category for every test image by finding
the training image with most similar features. Instead of 1 nearest
neighbor, you can vote based on k nearest neighbors which will increase
performance (although you need to pick a reasonable value for k). '''
from sklearn.neighbors import KNeighborsClassifier
from sklearn.multiclass import OneVsRestClassifier
from sklearn import svm
import numpy as np
def nearest_neighbor_classify(train_image_feats, train_labels, test_image_feats):

    '''
    Parameters
        ----------
        train_image_feats:  is an N x d matrix, where d is the dimensionality of the feature representation.
        train_labels: is an N x l cell array, where each entry is a string 
        			  indicating the ground truth one-hot vector for each training image.
    	test_image_feats: is an M x d matrix, where d is the dimensionality of the
    					  feature representation. You can assume M = N unless you've modified the starter code.
        
    Returns
        -------
    	is an M x l cell array, where each row is a one-hot vector 
        indicating the predicted category for each test image.

    Usefull funtion:
    	
    	# You can use knn from sci-kit learn.
        # Reference: https://scikit-learn.org/stable/modules/generated/sklearn.neighbors.KNeighborsClassifier.html
    '''

    model = KNeighborsClassifier(n_neighbors=7)
    model.fit(train_image_feats, train_labels)
    M = test_image_feats.shape[0]
    predicted_labels = np.zeros((M))
    # Predict the output
    for image in range(M):
        predicted_labels[image] = model.predict([test_image_feats[image]])

    return predicted_labels



'''This function will train a linear SVM for every category (i.e. one vs all)
and then use the learned linear classifiers to predict the category of
very test image. Every test feature will be evaluated with all 15 SVMs
and the most confident SVM will "win". Confidence, or distance from the
margin, is W*X + B where '*' is the inner product or dot product and W and
B are the learned hyperplane parameters. '''

def svm_classify(train_image_feats, train_labels, test_image_feats):

    '''
    Parameters
        ----------
        train_image_feats:  is an N x d matrix, where d is the dimensionality of the feature representation.
        train_labels: is an N x l cell array, where each entry is a string 
        			  indicating the ground truth one-hot vector for each training image.
    	test_image_feats: is an M x d matrix, where d is the dimensionality of the
    					  feature representation. You can assume M = N unless you've modified the starter code.
        
    Returns
        -------
    	is an M x l cell array, where each row is a one-hot vector 
        indicating the predicted category for each test image.

    Usefull funtion:
    	
    	# You can use svm from sci-kit learn.
        # Reference: https://scikit-learn.org/stable/modules/svm.html

    '''


    #Classifiers:
    

    classifier = OneVsRestClassifier(svm.SVC(C=3.0, kernel='linear', probability=True))
    classifier.fit(train_image_feats, train_labels)
    predicted_labels = []
    for test_image_feat in test_image_feats:
        # decision_function
        score = classifier.predict_proba(test_image_feat.reshape(1, -1))
        s = score[0]
        m = s.tolist()
        print("sdfsdf")
        index_max = max(xrange(len(m)), key=m.__getitem__)
        predicted_labels.append(index_max)

    return predicted_labels

