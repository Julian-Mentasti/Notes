# CPSC 425 Assignment 3
Julian Mentasti
90772385
e0q1b

## Removed Donkey Image:
![Removed Donkey](https://i.imgur.com/xdjnrWf.jpg)

## Succesfull removal of a leaf

### Orginal
![Flower Image original](https://i.imgur.com/zikruhM.jpg)

### After removing the leaf
![Flower Image sans leaf](https://i.imgur.com/mh8uclT.jpg)

## Unsuccessfull removal of the Carin

### Original
![Carin Image original](https://i.imgur.com/CHUFPi6.jpg)

### After removing the carin
![Carin Image sans Carin](https://i.imgur.com/2xzF7Lt.jpg)

### Reason for failure:
The texture replacement was unsuccessfull due to the lack of samples for the programme to match and replace the carin with. Moreover, the samples that it did have had edges oriented in the opposite direction as the edge direction of the patch being replaced
thus leaving an incoherent image.

## Question 7
patchL indicates the size of the texture patches. Thus a larger patch would mean that there is a large sample to take matches from and a greater context to fill in a hole. Hence, if pathL is too small, there will be a lacklustre amount of matches for a texture to be synthesised from leading to the replication appearing less accurate and less coherent. 

randomPatchSD is utilised to select the subsection of the patch to use as a sample. If we consistently used the same subsection to synthesise our textures from then, the resultant texture will be noticeably uniform. Thus the code uses random. Gauss (0, randomPatchSD) to randomly select a subsection of the patch with a uniform Gaussian distribution with a standard deviation being the variable randomPatchSD. This random element will allow for a more varied selection of matches for the texture; keeping in mind that those matches with a lower SSD will be chosen.   If randomPatchSD is too large, then the synthesised patches will look like a repetition of the texture patch since it will group larger chunks of the image. If randomPatchSD is too small, then it will lead to the production of a very uniform texture since the same matches will be used. 