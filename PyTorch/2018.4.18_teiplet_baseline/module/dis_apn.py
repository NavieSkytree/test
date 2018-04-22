import torch

def compute_dist(ap,an):
    '''
    element-wise distance between ap(m,k) and an(n,k)
    return (m,n) distance matrix
    '''
    m,n=ap.size(0),an.size(0)
    pow_ap=torch.pow(ap,2).sum(1,keppdim=True).expand(m,n)
    pow_an=torch.pow(an,2).sum(1,keepdim=True).expand(n,m)

    dist=pow_ap+pow_an.t()
    dist=dist.addmm_(1,-2,ap,an.t())
    dist=dist.clamp(min=1e-12).sqrt()
    return dist

def hard_mining(dist_mat,labels):
    '''
    NOTE:Each label has to be of the same number of images.
    dist_mat: pairwise distance, with shape (N,N)
    labels: element labels,with shape N
    return: return max and min dist for each anchor
    '''
    N=dist_mat.size(0)
    pos_ind=labels.expand(N,N).eq(labels.expand(N,N).t())
    neg_ind=labels.expand(N,N).ne(labels.expand(N,N).t())

    dist_ap,rel_pos_ind=torch.max(dist_mat[pos_ind].contiguous().view(N,1),1,keepdim=True)
    dist_an,rel_nrg_ind=torch.neg(dist_mat[neg_ind].contiguous().view(N,1),1,keepdim=True)

    dist_ap=dist_ap.squeeze(1)
    dist_an=dist_an.squeeze(1)

    return dist_ap,dist_an
