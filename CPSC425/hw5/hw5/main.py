#Starter code prepared by Borna Ghotbi, Polina Zablotskaia, and Ariel Shann for Computer Vision
#based on a MATLAB code by James Hays and Sam Birch 

import numpy as np
from util import sample_images, build_vocabulary, get_bags_of_sifts, get_average_hist
from classifiers import nearest_neighbor_classify, svm_classify
import matplotlib.pyplot as plt
import random
import itertools

from sklearn.metrics import accuracy_score, confusion_matrix

#For this assignment, you will need to report performance for sift features on two different classifiers:
# 1) Bag of sift features and nearest neighbor classifier
# 2) Bag of sift features and linear SVM classifier

#For simplicity you can define a "num_train_per_cat" vairable, limiting the number of
#examples per category. num_train_per_cat = 100 for intance.

#Sample images from the training/testing dataset. 
#You can limit number of samples by using the n_sample parameter.

print('Getting paths and labels for all train and test data\n')
train_image_paths, train_labels = sample_images("sift/test", n_sample=200)
test_image_paths, test_labels = sample_images("sift/test", n_sample=100)
       

''' Step 1: Represent each image with the appropriate feature
 Each function to construct features should return an N x d matrix, where
 N is the number of paths passed to the function and d is the 
 dimensionality of each image representation. See the starter code for
 each function for more details. '''

        
print('Extracting SIFT features\n')
vocab_size=50
kmeans = build_vocabulary(train_image_paths, vocab_size=vocab_size)

train_image_feats = get_bags_of_sifts(train_image_paths, kmeans)

""" START OF WORK FOR HISTOGRAMS

# return an array of (m*15) where each row is an average histogram
train_image_average_feats = get_average_hist(train_image_labels, train_image_feats)
print("-----------")
print(train_image_average_feats.shape)
for image in range(15):
    plt.bar(np.arange(len(train_image_average_feats[image])), train_image_average_feats[image])
    plt.xlabel('Vocabulary', fontsize=10)
    plt.ylabel('Noarmalized Average', fontsize=10)
    new_labels = list(set(train_image_labels))
    plt.title('Average historgram for Category: ' + new_labels[image])
    plt.show()

END OF WORK FOR HISTOGRAMS""" 

#If you want to avoid recomputing the features while debugging the
#classifiers, you can either 'save' and 'load' the extracted features
#to/from a file.

''' Step 2: Classify each test image by training and using the appropriate classifier
 Each function to classify test features will return an N x l cell array,
 where N is the number of test cases and each entry is a string indicating
 the predicted one-hot vector for each test image. See the starter code for each function
 for more details. '''

test_image_feats= get_bags_of_sifts(test_image_paths, kmeans)


print('Using nearest neighbor classifier to predict test set categories\n')


pred_labels_knn = nearest_neighbor_classify(train_image_feats, train_labels, test_image_feats)


print('Using support vector machine to predict test set categories\n')
#TODO: YOU CODE svm_classify function from classifers.py
pred_labels_svm = svm_classify(train_image_feats, train_labels, test_image_feats)



print('---Evaluation---\n')
# Step 3: Build a confusion matrix and score the recognition system for 
#         each of the classifiers.
# TODO: In this step you will be doing evaluation. 
# 1) Calculate the total accuracy of your model by counting number
#   of true positives and true negatives over all. 
# 2) Build a Confusion matrix and visualize it. 
#   You will need to convert the one-hot format labels back
#   to their category name format.

#Calculate the accuracy scores
a = accuracy_score(pred_labels_knn, test_labels, normalize=True)
print("KNN score: ", a)
b = accuracy_score(pred_labels_svm, test_labels, normalize=True)
print("SVM score: ", b)


class_dict = {0:"Bedroom",
		   1:"Coast",
		   2:"Forest",
		   3:"Highway",
		   4:"Industrial",
		   5:"InsideCity",
		   6:"Kitchen",
		   7:"LivingRoom",
		   8:"Mountain",
		   9:"Office",
		   10:"OpenCountry",
		   11:"Store",
		   12:"Street",
		   13:"Suburb",
		   14:"TallBuilding"}

def plot_confusion_matrix(cm, classes,
                          normalize=False,
                          title='Confusion matrix',
                          cmap=plt.cm.Blues):
    """
    This function prints and plots the confusion matrix.
    Normalization can be applied by setting `normalize=True`.
    """
    if normalize:
        cm = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]
        print("Normalized confusion matrix")
    else:
        print('Confusion matrix, without normalization')

    print(cm)

    plt.imshow(cm, interpolation='nearest', cmap=cmap)
    plt.title(title)
    plt.colorbar()
    tick_marks = np.arange(len(classes))
    plt.xticks(tick_marks, classes, rotation=45)
    plt.yticks(tick_marks, classes)

    fmt = '.2f' if normalize else 'd'
    thresh = cm.max() / 2.
    for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
        plt.text(j, i, format(cm[i, j], fmt),
                 horizontalalignment="center",
                 color="white" if cm[i, j] > thresh else "black")

    plt.ylabel('True label')
    plt.xlabel('Predicted label')
    plt.tight_layout()


# Compute confusion matrix

# For KNN
#Replace the category codes to string labels
test_labels_string = [ class_dict.get(item,item) for item in test_labels ]
pred_labels_knn_string = [ class_dict.get(item,item) for item in pred_labels_knn ]

cnf_matrix = confusion_matrix(test_labels_string, pred_labels_knn_string)
np.set_printoptions(precision=2)

# Plot non-normalized confusion matrix
plt.figure()
plot_confusion_matrix(cnf_matrix, classes=set(test_labels_string),
                      title='Confusion matrix, without normalization KNN')

# Plot normalized confusion matrix
plt.figure()
plot_confusion_matrix(cnf_matrix, classes=set(test_labels_string), normalize=True,
                      title='Normalized confusion matrix KNN')
plt.show()

# End of KNN

# For SVM
pred_labels_svm_string = [ class_dict.get(item,item) for item in pred_labels_svm ]

cnf_matrix_svm = confusion_matrix(test_labels_string, pred_labels_svm_string)
np.set_printoptions(precision=2)

# Plot non-normalized confusion matrix
plt.figure()
plot_confusion_matrix(cnf_matrix_svm, classes=set(test_labels_string),
                      title='Confusion matrix SVM')

# Plot normalized confusion matrix
plt.figure()
plot_confusion_matrix(cnf_matrix_svm, classes=set(test_labels_string), normalize=True,
                      title='Normalized confusion matrix SVM')
plt.show()



# Interpreting your performance with 100 training examples per category:
#  accuracy  =   0 -> Your code is broken (probably not the classifier's
#                     fault! A classifier would have to be amazing to
#                     perform this badly).
#  accuracy ~= .10 -> Your performance is chance. Something is broken or
#                     you ran the starter code unchanged.
#  accuracy ~= .50 -> Rough performance with bag of SIFT and nearest
#                     neighbor classifier. Can reach .60 with K-NN and
#                     different distance metrics.
#  accuracy ~= .60 -> You've gotten things roughly correct with bag of
#                     SIFT and a linear SVM classifier.
#  accuracy >= .70 -> You've also tuned your parameters well. E.g. number
#                     of clusters, SVM regularization, number of patches
#                     sampled when building vocabulary, size and step for
#                     dense SIFT features.
#  accuracy >= .80 -> You've added in spatial information somehow or you've
#                     added additional, complementary image features. This
#                     represents state of the art in Lazebnik et al 2006.
#  accuracy >= .85 -> You've done extremely well. This is the state of the
#                     art in the 2010 SUN database paper from fusing many 
#                     features. Don't trust this number unless you actually
#                     measure many random splits.
#  accuracy >= .90 -> You used modern deep features trained on much larger
#                     image databases.
#  accuracy >= .96 -> You can beat a human at this task. This isn't a
#                     realistic number. Some accuracy calculation is broken
#                     or your classifier is cheating and seeing the test
#                     labels.